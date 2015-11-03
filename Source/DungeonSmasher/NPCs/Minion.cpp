// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonSmasher.h"
#include "Minion.h"
#include "AI/Navigation/NavigationSystem.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMinion::AMinion()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMinion::BeginPlay()
{
	Super::BeginPlay();
	auto direction = FVector(FMath::RandRange(-5.0f, 5.0f), FMath::RandRange(-5.0f, 5.0f), 0.0F);
	MoveInDir(direction, 20);

}

// Called every frame
void AMinion::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	AController* controller = GetController();
	auto const NavSys = UNavigationSystem::GetCurrent(controller);
	auto const Distance = FVector::Dist(Destination, GetActorLocation());

	NavSys->SimpleMoveToLocation(controller, Destination);


	DrawDebugLine(
		GetWorld(),
		GetActorLocation(),
		Destination,
		color,
		false, -1, 0,
		12.333
		);
}

// Called to bind functionality to input
void AMinion::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AMinion::MoveInDir(FVector Direction, float Magnitude) {
	Direction.Z = 0;
	Destination = GetActorLocation() + Direction * Magnitude;
}
