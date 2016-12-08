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
	void Elevate(float DegreesPerSecond);
			
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20.0;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationInDegrees = 30.0; 
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationInDegrees = -10.0; 

};