// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankPlayerController.h"
#include "Engine/World.h"

#define OUT


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
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessed Tank: %s"), *MyTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Player Tank possessed!"));
	}
}

void AMyTankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


void AMyTankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	

	if (GetSightRayHitLocation(HitLocation)) // has "side-effect": is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());

		// Tell controlled tank to aim at this point
	}

}

bool AMyTankPlayerController::GetSightRayHitLocation(FVector& OutHitocation) const
{
	OutHitocation = FVector(1.0);
	return true;
}

