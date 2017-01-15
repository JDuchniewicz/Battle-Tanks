// Copyright 2016 Jakub Duchniewicz

#include "BattleTank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
	//UE_LOG(LogTemp, Warning, TEXT("BUMP: C++ Constructor Logging"));
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	//UE_LOG(LogTemp, Warning, TEXT("BUMP: C++ BeginPlay Logging"));
	Super::BeginPlay(); //Needed for BP Begin Play to run!!!
}
