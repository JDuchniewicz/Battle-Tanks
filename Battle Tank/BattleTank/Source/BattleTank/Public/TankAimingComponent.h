// Copyright 2016 Jakub Duchniewicz

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h" 

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	Empty
};
//Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();
	UFUNCTION(BlueprintCallable, Category = "Firing")
		int32 ReturnAmmo() const;
	void AimAt(FVector HitLocation); 

	EFiringState GetFiringState() const;
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	 float LaunchSpeed = 4000;
		
private:
	virtual void BeginPlay() override;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	bool IsBarrelMoving(FVector AimDirection);
	FVector AimDirection;

	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTime = 3;
	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		int32 RoundsLeft = 0;

};
