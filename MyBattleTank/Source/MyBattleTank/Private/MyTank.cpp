// Copyright FIXEO

#include "MyBattleTank/Public/MyTank.h"
#include "MyBattleTank/Public/MyTankAimingComponent.h"
#include "MyBattleTank/Public/MyTankBarrel.h"
#include "MyBattleTank/Public/MyTankTurret.h"
#include "MyBattleTank/Public/MyProjectile.h"
#include "MyBattleTank/Public/MyTankMovementComponent.h"
#include "Engine/World.h"





// Sets default values
AMyTank::AMyTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMyTank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void AMyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

void AMyTank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void AMyTank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimesInSeconds;
	
	if (Barrel && isReloaded) 
	{
		// Spawn a projectile at the socket location from the barrel
		FName SocketName = FName("Projectile");
		auto Projectile = GetWorld()->SpawnActor<AMyProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(SocketName),
			Barrel->GetSocketRotation(SocketName)
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
	
	
}
