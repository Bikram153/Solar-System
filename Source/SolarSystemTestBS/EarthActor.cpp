#include "EarthActor.h"

AEarthActor::AEarthActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SemiMajorAxis = 5300.0f;  
	SemiMinorAxis = 5000.0f;
	OrbitSpeed = 15.0f;  
	CurrentOrbitAngle = 0.0f;
}

void AEarthActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEarthActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(3.2f, 3.2f, 3.2f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = -50.0f; 

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

