#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MyTextWidget.h"
#include "YourPlayerController.generated.h"

UCLASS()
class SOLARSYSTEMTESTBS_API AYourPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
    AYourPlayerController();
    virtual void SetupInputComponent() override;


    UPROPERTY(EditDefaultsOnly, Category = "Widgets")
        TSubclassOf<class UUserWidget> WidgetClass;

    UMyTextWidget* WidgetInstance;

    UFUNCTION()
        void PerformRaycast();
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    UPROPERTY()
        class UInputMappingContext* PawnMappingContext;

    UPROPERTY()
        class UInputAction* MoveAction;

    UPROPERTY()
        UInputAction* HideAction = nullptr;

    UFUNCTION(BlueprintCallable, Category = "UI")
        void ShowWidget(double x,FString m, FString v, FString d);
    UFUNCTION(BlueprintCallable, Category = "UI")
        void HideWidget();
    AActor* HitActor;
};
