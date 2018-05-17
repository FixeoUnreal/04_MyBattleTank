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
	
private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// How close can the AI tank get 
	float AcceptanceRadius = 3000;

};
