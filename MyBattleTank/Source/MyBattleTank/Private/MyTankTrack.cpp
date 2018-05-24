// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankTrack.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"



UMyTankTrack::UMyTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMyTankTrack::BeginPlay()
{
	//Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UMyTankTrack::OnHit);
}

void UMyTankTrack::ApplySidewaysForce()
{
	// Calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	// Work out the required acceleration this frame to correct
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	// Calculate and apply sideways force
	UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectForce);
}

void UMyTankTrack::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0;
}

void UMyTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (ensure(TankRoot))
	{
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
}

void UMyTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>((CurrentThrottle + Throttle), -1, 1);
}
