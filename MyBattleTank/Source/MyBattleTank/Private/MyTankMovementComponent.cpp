// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankMovementComponent.h"
#include "MyBattleTank/Public/MyTankTrack.h"




void UMyTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UMyTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UMyTankMovementComponent::Initialise(UMyTankTrack * LeftTrackToSet, UMyTankTrack * RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

	//TODO prevent double speed due to dual control use
}
