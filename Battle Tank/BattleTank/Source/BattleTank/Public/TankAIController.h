// Copyright 2016 Jakub Duchniewicz

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;
	
private:
	virtual void Tick(float DeltaTime) override;
};
