// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyTank.h"
#include "GameFramework/PlayerController.h"
#include "MyTankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYBATTLETANK_API AMyTankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	AMyTank * GetControlledTank() const;

	virtual void BeginPlay() override;
	
};
