// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MyTankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hideCategories = ("Collision"))
class MYBATTLETANK_API UMyTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegressPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20; 

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;

};
