// Copyright 2016 Jakub Duchniewicz

#include "BattleTank.h"
#include "TankPlayerController.h"

void  ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing the tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))// will linetrace
	{
		GetControlledTank()->AimAt(HitLocation);
	}
	
	
	//If it hits landscape
		//Tell the controlled tank to aim at this point
}

//Get world location through the sight of crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const 
{
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	FVector LookDirection;
	//"De-project" the screen position of the crosshair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Linetrace along that direction and see what we have hit
		GetLookVectorHitLocation(HitLocation, LookDirection);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; //to be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector & HitLocation, FVector LookDirection) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);

	//linetrace
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
		))
	{
		HitLocation = HitResult.Location;
		return true;
	} 
	HitLocation = FVector(0);
	return false; //Linetrace didn't succeed
}


/*UWorld* World;
FRotator TurretRotation;
FVector &StartTrace;
FVector Direction;
FVector &EndTrace;
FHitResult &HitOut;

auto ControlledTank = GetControlledTank();
auto PlayerController = GetWorld()->GetFirstPlayerController()->GetPawn();
StartTrace = ControlledTank->GetActorLocation();
TurretRotation = PlayerController->GetActorRotation();
Direction = TurretRotation.Vector();
EndTrace = StartTrace + Direction * 2000;

FCollisionQueryParams TraceParams(FName(TEXT("AimTrace")), true, this);
TraceParams.bTraceComplex = true;

HitOut = FHitResult(ForceInit);

World->LineTraceSingleByObjectName(
HitOut,
StartTrace,
EndTrace,
FCollisionObjectQueryParams(ECollisionChannel::),
TraceParams,
)
*/
