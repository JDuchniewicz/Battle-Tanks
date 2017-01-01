// Copyright 2016 Jakub Duchniewicz

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void  ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ControlledTank && PlayerTank)
	{
		//Move Towards The player
		MoveToActor(PlayerTank, AcceptanceRadius);
		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); //TODO limit firing rate
	}

}


