// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTank.generated.h"

class UMyTankBarrel;
class UMyTankAimingComponent;

UCLASS()
class MYBATTLETANK_API AMyTank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UMyTankBarrel* BarrelToSet);

protected:
	UMyTankAimingComponent * TankAimingComponent = nullptr;


private:
	// Sets default values for this pawn's properties
	AMyTank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 100000; // TODO find sensible starting value 
	
};
