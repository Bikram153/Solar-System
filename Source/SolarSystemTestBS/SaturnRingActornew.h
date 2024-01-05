// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "SaturnRingActornew.generated.h"

UCLASS(config = Game)
class SOLARSYSTEMTESTBS_API ASaturnRingActornew : public AActor
{
	GENERATED_BODY()
	
public:	
	ASaturnRingActornew();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
        UProceduralMeshComponent* MeshComponent;

    UPROPERTY(EditAnywhere)
        float InnerRadius;

    UPROPERTY(EditAnywhere)
        float OuterRadius;

	const int32 NumSegments = 360;

    float CurrentOrbitAngle;

    void GenerateRingMesh();

	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMajorAxis;

	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMinorAxis;

	UPROPERTY(EditAnywhere, Category = "Orbit", Config)
		float OrbitSpeed;

};
