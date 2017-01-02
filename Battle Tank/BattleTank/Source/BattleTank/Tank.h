// Copyright 2016 Jakub Duchniewicz

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //paste all includes above this

//Forward Declarations
class UTankAimingComponent;
class UTankMovementComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000; 
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTime = 3;

	UTankBarrel* Barrel = nullptr;
	
	double LastFireTime = 0;
};
