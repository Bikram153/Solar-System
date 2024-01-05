#include "MarsActor.h"

AMarsActor::AMarsActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SemiMajorAxis = 5800.0f;  
	SemiMinorAxis = 5500.0f;
	OrbitSpeed = 13.0f;  
	CurrentOrbitAngle = 0.0f;
}

void AMarsActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMarsActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(2.6f, 2.6f, 2.6f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = -52.0f; 

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

