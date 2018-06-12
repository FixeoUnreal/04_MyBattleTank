// Copyright FIXEO

#include "MySpringWheel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"


// Sets default values
AMySpringWheel::AMySpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Physics Constraint"));
	SetRootComponent(MassWheelConstraint);

	Mass = CreateAbstractDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	Mass->SetupAttachment(MassWheelConstraint);

	Wheel = CreateAbstractDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(MassWheelConstraint);

	
}

// Called when the game starts or when spawned
void AMySpringWheel::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetAttachParentActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not null"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Null"));
	}
}

// Called every frame
void AMySpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

