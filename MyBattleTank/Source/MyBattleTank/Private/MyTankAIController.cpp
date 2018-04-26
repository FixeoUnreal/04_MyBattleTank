// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankAIController.h"


AMyTank* AMyTankAIController::GetControlledTank() const
{
	return Cast<AMyTank>(GetPawn());
}

void AMyTankAIController::BeginPlay()
{
	Super::BeginPlay();

	AMyTank* ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessed tank: %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Tank possed!"));
	}
}

