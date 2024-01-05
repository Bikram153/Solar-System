#include "UranusActor.h"

AUranusActor::AUranusActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SemiMajorAxis = 9500.0f;  
	SemiMinorAxis = 9200.0f;
	OrbitSpeed = 5.0f;  
	CurrentOrbitAngle = 0.0f;
}

void AUranusActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AUranusActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(4.7f, 4.7f, 4.7f);
	RootComponent->SetWorldScale3D(NewScale);

	FRotator NewRotation = GetActorRotation();
	float RotationSpeed = 54.0f; 

	NewRotation.Roll += RotationSpeed * DeltaTime; 

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

