// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankMovementComponent.h"
#include "MyBattleTank/Public/MyTankTrack.h"




void UMyTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UMyTankMovementComponent::Initialise(UMyTankTrack * LeftTrackToSet, UMyTankTrack * RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet){ return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

	//TODO prevent double speed due to dual control use
}
