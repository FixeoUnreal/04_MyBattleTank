// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyTank.h"
#include "GameFramework/PlayerController.h"
#include "MyTankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYBATTLETANK_API AMyTankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	AMyTank * GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	// Start the tank moving the barrel so that a shot would hit
	// where the crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
};
