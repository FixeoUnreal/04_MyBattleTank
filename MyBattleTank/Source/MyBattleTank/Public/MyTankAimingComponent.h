// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyTankAimingComponent.generated.h"

// Enum for aiming states
UENUM()
enum class EFiringStatus : uint8
{
	Aiming,
	Reloading,
	Locked
};

// Forward declaration
class UMyTankBarrel; 
class UMyTankTurret;

// Hold barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYBATTLETANK_API UMyTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UMyTankBarrel * BarrelToSet, UMyTankTurret * TurretToSet);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Reloading;

private:
	UMyTankBarrel * Barrel = nullptr;

	UMyTankTurret * Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
