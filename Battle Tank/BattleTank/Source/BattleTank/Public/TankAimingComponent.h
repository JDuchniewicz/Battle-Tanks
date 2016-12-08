// Copyright 2016 Jakub Duchniewicz

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h" 

//Forward declaration
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	//TODO Add SetTurretReference;


	void AimAt(FVector HitLocation, float LaunchSpeed); 
private:
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
