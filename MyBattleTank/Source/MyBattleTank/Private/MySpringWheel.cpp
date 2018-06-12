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

	Wheel = CreateAbstractDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(MassWheelConstraint);
}

// Called when the game starts or when spawned
void AMySpringWheel::BeginPlay()
{
	Super::BeginPlay();
	
	SetupConstraint();
}

void AMySpringWheel::SetupConstraint()
{
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	MassWheelConstraint->SetConstrainedComponents(
		BodyRoot,
		NAME_None,
		Wheel,
		NAME_None
	);
}

// Called every frame
void AMySpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



