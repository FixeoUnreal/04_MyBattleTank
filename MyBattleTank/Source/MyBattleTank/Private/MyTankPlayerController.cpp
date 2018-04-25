// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankPlayerController.h"


AMyTank* AMyTankPlayerController::GetControlledTank() const
{
	return Cast<AMyTank>(GetPawn());
}

void AMyTankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin PLay!"));
	AMyTank* MyTank = GetControlledTank();
	if (MyTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessed Tank: %s"), *MyTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Tank possessed!"));
	}
}
