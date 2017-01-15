// Copyright 2016 Jakub Duchniewicz

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
private:
	virtual void Tick(float DeltaTime) override;
	//How close the tank can get to player in cm
	float AcceptanceRadius = 3000; 
};
