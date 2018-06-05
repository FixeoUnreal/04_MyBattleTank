// Copyright FIXEO

#include "MySpringWheel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"


// Sets default values
AMySpringWheel::AMySpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mass = CreateAbstractDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	SetRootComponent(Mass);

	Wheel = CreateAbstractDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Mass);

	PhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Physics Constraint"));
	PhysicsConstraint->SetupAttachment(Mass);
}

// Called when the game starts or when spawned
void AMySpringWheel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMySpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

