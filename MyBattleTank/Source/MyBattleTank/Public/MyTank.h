// Copyright FIXEO

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTank.generated.h"

UCLASS()
class MYBATTLETANK_API AMyTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTank();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;
};
