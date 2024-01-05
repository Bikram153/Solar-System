#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrajectoryNeptune.generated.h"

class UProceduralMeshComponent;


UCLASS(config = Game)
class SOLARSYSTEMTESTBS_API ATrajectoryNeptune : public AActor
{
	GENERATED_BODY()

public:
	ATrajectoryNeptune();
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
