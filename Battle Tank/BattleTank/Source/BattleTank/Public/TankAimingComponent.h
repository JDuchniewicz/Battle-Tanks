// Copyright 2016 Jakub Duchniewicz

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h" 

//Enum for reloading state
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};

//Forward declaration
class UTankBarrel;
class UTankTurret;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed); 
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	UTankBarrel* Barrel = nullptr;
protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
		EFiringStatus FiringState = EFiringStatus::Reloading;
private:
	
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);
};
