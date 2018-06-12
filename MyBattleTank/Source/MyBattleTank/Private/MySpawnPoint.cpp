// Copyright FIXEO

#include "MySpawnPoint.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UMySpawnPoint::UMySpawnPoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMySpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	AActor* NewActor = GetWorld()->SpawnActor<AActor>(SpawnClass);
	if (!NewActor) { return; }
	NewActor->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);
}


// Called every frame
void UMySpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

