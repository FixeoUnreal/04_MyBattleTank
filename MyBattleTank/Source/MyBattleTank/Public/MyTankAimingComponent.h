// Copyright FIXEO

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyTankAimingComponent.generated.h"

// Enum for aiming states
UENUM()
enum class EFiringState : uint8
{
	Aiming,
	Reloading,
	Locked, 
	NoAmmo
};

// Forward declaration
class UMyTankBarrel; 
class UMyTankTurret;
class AMyProjectile;

// Hold barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYBATTLETANK_API UMyTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyTankAimingComponent();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UMyTankBarrel * BarrelToSet, UMyTankTurret * TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Action")
	void Fire();

	EFiringState GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	int32 AmmoNumber = 2;

	virtual void BeginPlay() override;

private:
	UMyTankBarrel * Barrel = nullptr;

	UMyTankTurret * Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AMyProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimesInSeconds = 3;

	double LastFireTime = 0;

	FVector AimDirection;

	void MoveBarrelTowards(FVector AimDirection);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	bool IsBarrelMoving();
};
