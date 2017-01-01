// Copyright 2016 Jakub Duchniewicz

#include "BattleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApllied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApllied, ForceLocation);
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle: %f"), *Name, Throttle);
}