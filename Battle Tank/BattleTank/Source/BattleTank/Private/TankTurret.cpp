// Copyright 2016 Jakub Duchniewicz

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Fmod(RelativeSpeed + 360.0f, 360.0f);
	//RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1); //we need to check how the yaw clamping will work
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}

