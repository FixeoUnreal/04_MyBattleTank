// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyBattleTank/Public/MyTank.h"
#include "MyTankAIController.generated.h"

/**
 * 
 */
UCLASS()
class MYBATTLETANK_API AMyTankAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	virtual void BeginPlay() override;
	
	AMyTank * GetControlledTank() const;

	APawn* GetPlayerTankPawn() const;

};
