// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "Ability.h"
#include <Vector.h>


// Sets default values for this component's properties
UAbility::UAbility()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbility::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAbility::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (onCD) {
		cdRemaining -= DeltaTime;
		if (cdRemaining < 0) onCD = false;
	}
}

// Called when the ability is used
void UAbility::Use()
{
	if (!onCD) {
		onCD = true;
		cdRemaining = cooldown;
	}
}

// Call to see how much threat the ability represents
float UAbility::Threat(FVector DistanceToTarget) {
	if (!onCD && DistanceToTarget.Dist(DistanceToTarget, FVector::ZeroVector) < range)
		return damage;
	return 0;
}
