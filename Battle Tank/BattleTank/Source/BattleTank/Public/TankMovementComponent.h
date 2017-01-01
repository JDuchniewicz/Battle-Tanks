// Copyright 2016 Jakub Duchniewicz

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * Responsible for driving the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float Throw);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UPROPERTY(EditDefaultsOnly)
		float Speed = 100.0; // TODO do we need it
	
private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
	
};
