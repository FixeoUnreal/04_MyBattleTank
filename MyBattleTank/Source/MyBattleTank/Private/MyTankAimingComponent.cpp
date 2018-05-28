// Copyright FIXEO

#include "MyBattleTank/Public/MyTankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "MyBattleTank/Public/MyTankBarrel.h"
#include "MyBattleTank/Public/MyTankTurret.h"
#include "MyBattleTank/Public/MyProjectile.h"


// Sets default values for this component's properties
UMyTankAimingComponent::UMyTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMyTankAimingComponent::AimAt(FVector HitLocation)
{
	auto OurTankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation();
	if (!ensure(Barrel && Turret)) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	// Calculate the OutLauchVelocity
	if (bHaveAimSolution)
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
	}
	// If no solution found do nothing
}

void UMyTankAimingComponent::Initialise(UMyTankBarrel * BarrelToSet, UMyTankTurret * TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UMyTankAimingComponent::Fire()
{
	if (FiringState != EFiringState::Reloading && AmmoNumber > 0)
	{
		if (!ensure(Barrel)) { return; }
		if(!ensure(ProjectileBlueprint)) { return; }
		// Spawn a projectile at the socket location from the barrel
		FName SocketName = FName("Projectile");
		auto Projectile = GetWorld()->SpawnActor<AMyProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(SocketName),
			Barrel->GetSocketRotation(SocketName)
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		AmmoNumber--;
	}
	if (AmmoNumber <= 0)
	{
		FiringState = EFiringState::NoAmmo;
	}
}

EFiringState UMyTankAimingComponent::GetFiringState() const
{
	return FiringState;
}

void UMyTankAimingComponent::BeginPlay()
{
	// So first fire is after initial reload
	LastFireTime = FPlatformTime::Seconds();
}

void UMyTankAimingComponent::MoveBarrelTowards(FVector AimDirectionParam)
{
	// Work-out difference between current barrel rotation and AimDirection
	if (!ensure(Barrel && Turret)) { return; }
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirectionParam.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch); 
	//Always yaw the shortest way
	if (FMath::Abs(DeltaRotator.Yaw) > 180.F)
	{
		DeltaRotator.Yaw *= -1.F;
	}
	Turret->Rotate(DeltaRotator.Yaw);
}

void UMyTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (FiringState == EFiringState::NoAmmo) { return; }
	if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimesInSeconds)
	{
		FiringState = EFiringState::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
	}
	else
	{
		FiringState = EFiringState::Locked;
	}
}

bool UMyTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }
	auto BarrelForward = Barrel->GetForwardVector();
	return !(AimDirection.Equals(BarrelForward, 0.01));
}
