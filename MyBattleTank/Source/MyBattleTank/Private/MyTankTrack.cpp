// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankTrack.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "MySpringWheel.h"
#include "Components/SceneComponent.h"
#include "MySpawnPoint.h"



UMyTankTrack::UMyTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

TArray<AMySpringWheel*> UMyTankTrack::GetWheels() const
{
	TArray<AMySpringWheel*> ResultArray;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	TArray<AMySpringWheel*> Wheels;
	for (USceneComponent* Child : Children)
	{
		auto SpawnPointChild = Cast<UMySpawnPoint>(Child);
		if(!SpawnPointChild){ continue; }

		AActor* SpawnedChild = SpawnPointChild->GetSpawnedActor();
		auto SpringWheel = Cast<AMySpringWheel>(SpawnedChild);

		if (!SpringWheel) { continue; }
		ResultArray.Add(SpringWheel);
	}

	return ResultArray;
}

void UMyTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();
	for (AMySpringWheel* Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}

void UMyTankTrack::SetThrottle(float Throttle)
{
	float ThrottleToSet = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(ThrottleToSet);
}
