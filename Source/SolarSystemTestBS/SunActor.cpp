#include "SunActor.h"

ASunActor::ASunActor()
{
	PrimaryActorTick.bCanEverTick = true;

	FVector OriginLocation = FVector(0.0f, 0.0f, 0.0f);
	SetActorLocation(OriginLocation);
}

void ASunActor::BeginPlay()
{
	Super::BeginPlay();

}

void ASunActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewScale = FVector(30.0f, 30.0f, 30.0f);
	RootComponent->SetWorldScale3D(NewScale);
}

