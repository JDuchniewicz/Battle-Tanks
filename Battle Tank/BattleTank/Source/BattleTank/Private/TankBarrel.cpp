// Copyright 2016 Jakub Duchniewicz

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond)
 {
		// Move the barrel the right amount this frame
		// Given a max elevation speed, and the frame time
		UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() called at speed %f"), DegreesPerSecond);
}

