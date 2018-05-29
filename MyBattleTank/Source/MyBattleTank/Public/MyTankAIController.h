// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyTankAIController.generated.h"

class AMyTank;

/**
 * 
 */
UCLASS()
class MYBATTLETANK_API AMyTankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// How close can the AI tank get 
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000;
	
private:
	virtual void SetPawn(APawn* InPawn) override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnTankDeath();
};
