#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrajectorySaturn.generated.h"

class UProceduralMeshComponent;

UCLASS()
class SOLARSYSTEMTESTBS_API ATrajectorySaturn : public AActor
{
	GENERATED_BODY()

public:
	ATrajectorySaturn();
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
