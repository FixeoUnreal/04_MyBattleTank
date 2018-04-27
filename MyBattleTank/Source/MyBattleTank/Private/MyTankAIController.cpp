// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankAIController.h"
#include "Engine/World.h"


AMyTank* AMyTankAIController::GetControlledTank() const
{
	return Cast<AMyTank>(GetPawn());
}

APawn * AMyTankAIController::GetPlayerTankPawn() const
{
	return GetWorld()->GetFirstPlayerController()->GetPawn();
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

	AMyTank* PLayerTank = Cast<AMyTank>(GetPlayerTankPawn());
	if (PLayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *PLayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can not find player tank!"));
	}
}



