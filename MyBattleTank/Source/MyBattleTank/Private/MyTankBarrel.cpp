// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankBarrel.h"
#include "Engine/World.h"

void UMyTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// given a max elevation speed and the frame time
	
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampNewElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(ClampNewElevation,0,0));
}


