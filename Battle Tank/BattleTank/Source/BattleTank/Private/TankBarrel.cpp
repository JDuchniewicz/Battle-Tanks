// Copyright 2016 Jakub Duchniewicz

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
 {
		// Move the barrel the right amount this frame
		// Given a max elevation speed, and the frame time
		RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	
		auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
		auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

		auto ClampedElevation  = FMath::Clamp<float>(RawNewElevation, MinElevationInDegrees, MaxElevationInDegrees);

		SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}

