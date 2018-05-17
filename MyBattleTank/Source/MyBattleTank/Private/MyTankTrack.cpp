// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankTrack.h"




void UMyTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (TankRoot)
	{
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No root tank found!"));
	}
}
