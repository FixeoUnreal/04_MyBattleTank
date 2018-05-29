// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankAIController.h"
#include "Engine/World.h"
#include "MyBattleTank/Public/MyTankAimingComponent.h"
#include "MyBattleTank/Public/MyTank.h"


void AMyTankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<AMyTank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// Subscribe our local method to the tank's death event
		AMyTank* ControlledTank = Cast<AMyTank>(GetPawn());
		if (ControlledTank)
		{
			ControlledTank->TankDeath.AddUniqueDynamic(this, &AMyTankAIController::OnTankDeath);
		}
	}
}

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
		if(ControlledAimComp->GetFiringState()  == EFiringState::Locked)
		{
			ControlledAimComp->Fire(); // TPDP don't fire every frame
		}
	}
}

void AMyTankAIController::OnTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("AI Tank %s died"), *GetPawn()->GetName());
}

