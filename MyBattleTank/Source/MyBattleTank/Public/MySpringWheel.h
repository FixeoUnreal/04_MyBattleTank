// Copyright FIXEO

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySpringWheel.generated.h"

class UPhysicsConstraintComponent;
class UStaticMeshComponent;

UCLASS()
class MYBATTLETANK_API AMySpringWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySpringWheel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Mass = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Wheel = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent* MassWheelConstraint = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
