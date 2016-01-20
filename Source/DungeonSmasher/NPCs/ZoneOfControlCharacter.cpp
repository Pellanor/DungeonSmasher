// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "ZoneOfControlCharacter.h"


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

}

// Called to bind functionality to input
void AZoneOfControlCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

