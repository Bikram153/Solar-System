#include "JupiterActor.h"

AJupiterActor::AJupiterActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SemiMajorAxis = 6500.0f;  
	SemiMinorAxis = 6200.0f;
	OrbitSpeed = 10.0f;  
	CurrentOrbitAngle = 0.0f;
}

void AJupiterActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AJupiterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(7.6f, 7.6f, 7.6f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = -70.0f; 

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

