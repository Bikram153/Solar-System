#include "YourPlayerController.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputMappingContext.h"

void AYourPlayerController::BeginPlay()
{
    Super::BeginPlay();

    bShowMouseCursor = true;
    if (!WidgetInstance && WidgetClass)
    {
        WidgetInstance = CreateWidget<UMyTextWidget>(this, WidgetClass);
        WidgetInstance->AddToViewport();
        HideWidget();
    }
}
AYourPlayerController::AYourPlayerController() {

    static ConstructorHelpers::FClassFinder<UMyTextWidget> panelWidgetClass(TEXT("/Game/MyTextWidget_BP"));
    WidgetClass = panelWidgetClass.Class;
}


void AYourPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (HitActor)
    {
        FVector V = HitActor->GetActorLocation();
        double XValue = V.X;
        double YValue = V.Y;
        double XSquared = FMath::Square(XValue);
        double YSquared = FMath::Square(YValue);
        double Distance = FMath::Sqrt(XSquared + YSquared);
        FString mass = "", velocity = "", diameter = "";

        FVector ActorScale = HitActor->GetActorScale3D();
        FVector DesiredScale = FVector(30.f, 30.f, 30.f); 

        if (Distance <= 10500.0f && Distance >= 10200.0f) {
            mass = "Neptune Mass: 1.02 x 1026 kg";
            velocity = "Neptune Velocity: 12,460 miles an hour";
            diameter = "Neptune Diameter: 34,503 miles";
        }
        else if (Distance <= 9500.0f && Distance >= 9200.0f) {
            mass = "Uranus Mass: 8.681 x 10^25 kg";
            velocity = "Uranus Velocity: 15,290 miles per hour";
            diameter = "Uranus Diameter: 31,000 miles";
        }
        else if (Distance <= 8000.0f && Distance >= 7700.0f) {
            mass = "Saturn Mass: 5.683 x 10^26 kg";
            velocity = "Saturn Velocity: 21,637 miles per hour";
            diameter = "Saturn Diameter: 72,400 miles";
        }
        else if (Distance <= 6500.0f && Distance >= 6200.0f) {
            mass = "Jupiter Mass: 1.899 x 1027 kg";
            velocity = "Jupiter Velocity: 29,236 miles per hour";
            diameter = "Jupiter Diameter: 88,695 miles";
        }
        else if (Distance <= 5800.0f && Distance >= 5500.0f) {
            mass = "Mars Mass: 6.39 x 10^23 kg";
            velocity = "Mars Velocity: 53,979 miles per hour";
            diameter = "Mars Diameter: 4,222 miles";
        }
        else if (Distance <= 5300.0f && Distance >= 5000.0f) {
            mass = "Earth Mass: 5.972 x 10^24 kg";
            velocity = "Earth Velocity: 67,000 miles per hour";
            diameter = "Earth Diameter: 7,926 miles";
        }
        else if (Distance <= 4800.0f && Distance >= 4500.0f) {
            mass = "Venus Mass: 4.867 x 10^24 kg";
            velocity = "Venus Velocity: 78,341 miles per hour";
            diameter = "Venus Diameter: 7,520.8 miles";
        }
        else if (Distance <= 4300.0f && Distance >= 4000.0f) {
            mass = "Mercury Mass: 3.30104 x 1023 kg";
            velocity = "Mercury Velocity: 107,082 miles per hour";
            diameter = "Mercury Diameter: 3,031.9 miles";
        }
        else if (ActorScale.Equals(DesiredScale)) {
            mass = "Sun Mass: 1.9891 x 1030 kg";
            velocity = "Sun Velocity:  448,000 miles per hour";
            diameter = "Sun Diameter: 865,000 miles";
        }
        else
            diameter = "You Have Clicked On an Orbit";
        if (WidgetInstance)
        {
            ShowWidget(Distance, mass, velocity, diameter);
        }
    }
 }
void AYourPlayerController::PerformRaycast()
{
    FVector WorldLocation, WorldDirection;
    DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

    FVector Start = WorldLocation;
    FVector End = Start + WorldDirection * 10000000.f; 

    FHitResult HitResult;
    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(this); 

    if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams))
    {
        HitActor = HitResult.GetActor();
    }
}

void AYourPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    PawnMappingContext = NewObject<UInputMappingContext>(this);

    MoveAction = NewObject<UInputAction>(this);
    MoveAction->ValueType = EInputActionValueType::Axis3D;
    PawnMappingContext->MapKey(MoveAction, EKeys::LeftMouseButton);
    UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(this->InputComponent);
    EIC->BindAction(MoveAction, ETriggerEvent::Started, this, &AYourPlayerController::PerformRaycast);

    HideAction = NewObject<UInputAction>(this);
    HideAction->ValueType = EInputActionValueType::Axis3D;
    PawnMappingContext->MapKey(HideAction, EKeys::RightMouseButton);
    EIC->BindAction(HideAction, ETriggerEvent::Triggered, this, &AYourPlayerController::HideWidget);

    UEnhancedInputLocalPlayerSubsystem* Subsystem =
        this->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    check(Subsystem);
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(this->PawnMappingContext, 0);
}

void AYourPlayerController::HideWidget()
{
    if (WidgetInstance)
    {
        WidgetInstance->SetVisibility(ESlateVisibility::Hidden);
        UE_LOG(LogTemp, Warning, TEXT("Widget hidden"));
        HitActor = nullptr;
    }
}
void AYourPlayerController::ShowWidget(double x, FString m, FString v, FString d)
{
    if (WidgetInstance)
    {
        FString Message = FString::Printf(TEXT("Current Distance From Sun: %f"), x);
        if (x == 0.000000)
            Message = "";
        WidgetInstance->SetMessage(FText::FromString(Message), FText::FromString(m), FText::FromString(v), FText::FromString(d));
        WidgetInstance->SetVisibility(ESlateVisibility::Visible);
        UE_LOG(LogTemp, Warning, TEXT("Some warning message"));
    }
}
