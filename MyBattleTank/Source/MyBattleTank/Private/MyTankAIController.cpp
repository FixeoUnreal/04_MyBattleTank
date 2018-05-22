// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankAIController.h"
#include "Engine/World.h"
#include "MyBattleTank/Public/MyTankAimingComponent.h"


void AMyTankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AMyTankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* PLayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	APawn* ControlledTank = GetPawn();
	auto ControlledAimComp = ControlledTank->FindComponentByClass<UMyTankAimingComponent>();

	if (!ensure(ControlledAimComp)) { return; }
	
	if (ensure(PLayerTank && ControlledTank))
	{
		// Move towards player
		MoveToActor(PLayerTank, AcceptanceRadius); // TODO check acceptance radius
		
		// aim towards player
		ControlledAimComp->AimAt(PLayerTank->GetActorLocation());

		// fire if ready
		ControlledAimComp->Fire(); // TPDP don't fire every frame
	}
}

