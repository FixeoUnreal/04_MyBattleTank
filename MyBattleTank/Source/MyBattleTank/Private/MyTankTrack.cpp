// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankTrack.h"




void UMyTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (ensure(TankRoot))
	{
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
}
