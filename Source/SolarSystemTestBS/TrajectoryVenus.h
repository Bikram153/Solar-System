// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrajectoryVenus.generated.h"

class UProceduralMeshComponent;

UCLASS()
class SOLARSYSTEMTESTBS_API ATrajectoryVenus : public AActor
{
	GENERATED_BODY()

public:
	ATrajectoryVenus();
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
