// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "ZoneOfControlCharacter.h"
#include "Ability.h"
#include <DrawDebugHelpers.h>
#include "AI/Navigation/NavigationSystem.h"
#include "AI/Navigation/NavigationPath.h"


// Sets default values
AZoneOfControlCharacter::AZoneOfControlCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZoneOfControlCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZoneOfControlCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	TArray<UAbility*> abilities;
	GetComponents(abilities);
	for (auto ability : abilities)
	{
		if (!ability->onCD) {
			DrawDebugSphere(
				GetWorld(),
				GetActorLocation(), //Center
				ability->range, //Radius
				32, //Segments
				FColor(ability->damage, 0, 0)
				);
		}
	}
}

// Called to bind functionality to input
void AZoneOfControlCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

// Call to see how much threat the character represents
float AZoneOfControlCharacter::Threat(FVector Location) {
	AController* controller = GetController();
	auto const NavSys = UNavigationSystem::GetCurrent(controller);
	auto path = NavSys->FindPathToLocationSynchronously(GetWorld(), Location, GetActorLocation());


	float threat = 0.0;
	TArray<UAbility*> abilities;
	GetComponents(abilities);
	for (auto ability : abilities) {
		if (!ability->onCD) {
			if (path->GetPathLength() <= ability->range) {
				threat += ability->damage;
			}
		}
	}
	return threat;
}
