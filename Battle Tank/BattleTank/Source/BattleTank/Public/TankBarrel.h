// Copyright 2016 Jakub Duchniewicz

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
		
public:
	//-1 is downwards and +1 is upwards
	void Elevate(float RelativeSpeed);
			
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10.0;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationInDegrees = 35.0; 
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationInDegrees = 0.0; 

};