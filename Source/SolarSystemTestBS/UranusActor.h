#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UranusActor.generated.h"

UCLASS(config = Game)
class SOLARSYSTEMTESTBS_API AUranusActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AUranusActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMajorAxis; 

	UPROPERTY(EditAnywhere, Category = "Orbit")
		float SemiMinorAxis; 

	UPROPERTY(EditAnywhere, Category = "Orbit", Config)
		float OrbitSpeed; 

	float CurrentOrbitAngle;
};
