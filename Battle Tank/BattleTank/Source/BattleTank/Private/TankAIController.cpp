// Copyright 2016 Jakub Duchniewicz

#include "BattleTank.h"
#include "TankAIController.h"


ATank * ATankAIController::GetPlayerTank() const
{
	AActor* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	else
	{
		return Cast<ATank>(PlayerPawn);
	}
}

void  ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player not possesing the tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Tank %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}


