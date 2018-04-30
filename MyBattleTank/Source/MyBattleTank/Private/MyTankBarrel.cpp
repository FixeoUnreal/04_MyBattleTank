// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankBarrel.h"

void UMyTankBarrel::Elevate(float DegressPerSecond)
{
	// Move the barrel the right amount this frame
	// given a max elevation speed and the frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate() called at speed: %f"), DegressPerSecond);
}


