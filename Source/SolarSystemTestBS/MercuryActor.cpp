#include "MercuryActor.h"

AMercuryActor::AMercuryActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SemiMajorAxis = 4300.0f;  
	SemiMinorAxis = 4000.0f;
	OrbitSpeed = 25.0f;  
	CurrentOrbitAngle = 0.0f;
}

void AMercuryActor::BeginPlay()
{
	Super::BeginPlay();

}

void AMercuryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(2.2f, 2.2f, 2.2f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = -75.0f; 

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