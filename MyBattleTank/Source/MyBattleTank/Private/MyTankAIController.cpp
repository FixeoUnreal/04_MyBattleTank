// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankAIController.h"
#include "Engine/World.h"
#include "MyBattleTank/Public/MyTank.h"




AMyTank* AMyTankAIController::GetControlledTank() const
{
	return Cast<AMyTank>(GetPawn());
}

AMyTank * AMyTankAIController::GetPlayerTank() const
{
	return Cast<AMyTank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void AMyTankAIController::BeginPlay()
{
	Super::BeginPlay();

	/*AMyTank* ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessed tank: %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Tank possessed!"));
	}*/

	AMyTank* PLayerTank =GetPlayerTank();
	if (PLayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *PLayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can not find player tank!"));
	}
}

void AMyTankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AMyTank* PLayerTank = GetPlayerTank();
	AMyTank* ControlledTank = GetControlledTank();
	
	if (PLayerTank && ControlledTank)
	{
		// TODO Move towards player
		
		// aim towards player
		ControlledTank->AimAt(PLayerTank->GetActorLocation());

		// fire if ready
	}
}

