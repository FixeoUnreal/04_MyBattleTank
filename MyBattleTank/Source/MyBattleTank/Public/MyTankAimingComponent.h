// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyTankAimingComponent.generated.h"

// Forward declaration
class UMyTankBarrel; 

// Hold barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYBATTLETANK_API UMyTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyTankAimingComponent();

	void SetBarrelReference(UMyTankBarrel * BarrelToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

	// TODO add SetTurretReference

private:
	UMyTankBarrel * Barrel = nullptr;
	
	void MoveBarrelTowards(FVector AimDirection);
};
