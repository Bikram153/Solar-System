#include "SaturnActor.h"

ASaturnActor::ASaturnActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SemiMajorAxis = 8000.0f;  
	SemiMinorAxis = 7700.0f;
	OrbitSpeed = 7.0f;  
	CurrentOrbitAngle = 0.0f;

}

void ASaturnActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASaturnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(5.2f, 5.2f, 5.2f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = -65.0f; 

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

