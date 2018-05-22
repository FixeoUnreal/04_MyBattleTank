// Copyright FIXEO

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTank.generated.h"

class UMyTankBarrel;
class UMyTankTurret;
class UMyTankAimingComponent;
class AMyProjectile;

UCLASS()
class MYBATTLETANK_API AMyTank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Action")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UMyTankAimingComponent * TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	AMyTank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; 

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AMyProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimesInSeconds = 100;

	// Local barrel reference for spawning projectiles
	UMyTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
	
};
