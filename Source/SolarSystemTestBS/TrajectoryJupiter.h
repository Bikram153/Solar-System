#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrajectoryJupiter.generated.h"

class UProceduralMeshComponent;
const int32 NumSegments = 380;

UCLASS()
class SOLARSYSTEMTESTBS_API ATrajectoryJupiter : public AActor
{
	GENERATED_BODY()

public:
	ATrajectoryJupiter();
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
