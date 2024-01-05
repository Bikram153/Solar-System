#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MercuryTrajectory.generated.h"

class UProceduralMeshComponent;


UCLASS()
class SOLARSYSTEMTESTBS_API ATrajectoryMercury : public AActor
{
	GENERATED_BODY()

public:
	ATrajectoryMercury();
private:
	const int32 NumSegments = 360;

protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Materials")
		UMaterialInterface* TrajectoryMaterial;

	void GenerateHollowEllipseMesh();
};
