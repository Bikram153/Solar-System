#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrajectoryUranus.generated.h"

class UProceduralMeshComponent;

UCLASS()
class SOLARSYSTEMTESTBS_API ATrajectoryUranus : public AActor
{
	GENERATED_BODY()

public:
	ATrajectoryUranus();
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
