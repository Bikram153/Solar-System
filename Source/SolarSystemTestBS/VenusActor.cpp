#include "VenusActor.h"

AVenusActor::AVenusActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SemiMajorAxis = 4800.0f;  
	SemiMinorAxis = 4500.0f;
	OrbitSpeed = 20.0f;  
	CurrentOrbitAngle = 0.0f;
}

void AVenusActor::BeginPlay()
{
	Super::BeginPlay();

}

void AVenusActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(3.0f, 3.0f, 3.0f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = 60.0f; 

	NewRotation.Yaw += RotationSpeed * DeltaTime; 

	SetActorRotation(NewRotation);

	const FVector NewLocation = FVector(
		SemiMajorAxis * FMath::Cos(FMath::DegreesToRadians(CurrentOrbitAngle)),
		SemiMinorAxis * FMath::Sin(FMath::DegreesToRadians(CurrentOrbitAngle)),
		GetActorLocation().Z
	);

	SetActorLocation(NewLocation);

	CurrentOrbitAngle += OrbitSpeed * DeltaTime;
	if (CurrentOrbitAngle >= 360.0f)
	{
		CurrentOrbitAngle = 0.0f;
	}


}
