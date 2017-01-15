// Copyright 2016 Jakub Duchniewicz

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //paste all includes above this

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:


private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
