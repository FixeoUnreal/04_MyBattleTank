// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankAIController.h"
#include "Engine/World.h"
#include "MyBattleTank/Public/MyTank.h"


void AMyTankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AMyTankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AMyTank* PLayerTank = Cast<AMyTank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	AMyTank* ControlledTank = Cast<AMyTank>(GetPawn());
	
	if (ensure(PLayerTank && ControlledTank))
	{
		// Move towards player
		MoveToActor(PLayerTank, AcceptanceRadius); // TODO check acceptance radius
		
		// aim towards player
		ControlledTank->AimAt(PLayerTank->GetActorLocation());

		// fire if ready
		ControlledTank->Fire(); // TPDP don't fire every frame
	}
}

