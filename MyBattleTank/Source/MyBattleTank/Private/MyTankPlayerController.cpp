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
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());

		// Tell controlled tank to aim at this point
	}

}

// Get world location of line trace through crosshair, true if hits landscape
bool AMyTankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair direction in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("Screen location of dot: %s"), *ScreenLocation.ToString());

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("World direction: %s"), *LookDirection.ToString());

		// Line-trace along that LookDirection and see what we hit (up to max range)
		if (GetLookVectorHitLocation(LookDirection, HitLocation))
		{
			
		}
	}

	return true;
}

bool AMyTankPlayerController::GetLookDirection(FVector2D &ScreenLocation, FVector& LookDirection) const
{
	FVector OutCameraWorldLocation;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OutCameraWorldLocation, LookDirection);
	
}

bool AMyTankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		HitLocation = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0);
	return false; // Line-trace didn't succeed
}