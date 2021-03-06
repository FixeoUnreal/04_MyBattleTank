// Copyright FIXEO

#include "MyBattleTank/Public/MyTank.h"
#include "Engine/World.h"





// Sets default values
AMyTank::AMyTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}

void AMyTank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float AMyTank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

float AMyTank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		TankDeath.Broadcast();
	}
	
	return DamageToApply;
}

