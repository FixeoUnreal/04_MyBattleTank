// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank/Public/MyTankAimingComponent.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UMyTankAimingComponent::UMyTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyTankAimingComponent::AimAt(FVector HitLocation)
{
	auto OurTankName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at:%s"), *OurTankName, *HitLocation.ToString());
}

