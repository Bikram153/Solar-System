#include "NeptuneActor.h"

ANeptuneActor::ANeptuneActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SemiMajorAxis = 10500.0f;  
	SemiMinorAxis = 10200.0f;
	OrbitSpeed = 3.0f;  
	CurrentOrbitAngle = 0.0f;
}

void ANeptuneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANeptuneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(4.0f, 4.0f, 4.0f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = -55.0f; 

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

