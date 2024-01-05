#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SunActor.generated.h"

UCLASS()
class SOLARSYSTEMTESTBS_API ASunActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASunActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
