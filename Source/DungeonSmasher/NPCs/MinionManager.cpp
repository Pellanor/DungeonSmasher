// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "MinionManager.h"
#include <DungeonSmasher/Boid.h>
#include "MinionController.h"
#include <Runtime/Engine/Public/Engine.h>


// Sets default values
AMinionManager::AMinionManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMinionManager::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
	FVector thisSpawnPos;

	for (auto i = 0; i < InitialMinionCount; i++)
	{
		thisSpawnPos.X = FMath::RandRange(MinionSpawnBoundsStart.X, MinionSpawnBoundsEnd.X);
		thisSpawnPos.Y = FMath::RandRange(MinionSpawnBoundsStart.Y, MinionSpawnBoundsEnd.Y);
		thisSpawnPos.Z = 200;
		auto MinionClass = FindObject<UClass>(ANY_PACKAGE, TEXT("MyMinion_C"));
		AMinion* spawnedMinion;
		if (MinionClass) {
			spawnedMinion = World->SpawnActor<AMinion>(MinionClass, thisSpawnPos, FRotator(0.0f));
		} else {
			UE_LOG(LogTemp, Warning, TEXT("Failed to load blueprint MyMinion_C"));
			spawnedMinion = World->SpawnActor<AMinion>(AMinion::StaticClass(), thisSpawnPos, FRotator(0.0f));
		}
		if (i == 0) {
			spawnedMinion->color = FColor(0, 255, 0);
		}
		minions.Add(spawnedMinion);
	}
}

// Called every frame
void AMinionManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	centreOfMass = GetCentreOfMass();
	averageVelocity = GetAverageVelocity();

	for (auto i = 0; i < minions.Num(); ++i) {
		if (minions[i]) {
			FVector Cohesion = (AMinionManager::DistanceFromCenterOfMass(minions[i]) * CohesionWeight).GetClampedToMaxSize(CohesionClamp);
			FVector Avoid = (AMinionManager::AvoidOtherMinions(minions[i]) * AvoidWeight).GetClampedToMaxSize(AvoidClamp);
			FVector Align = (AMinionManager::MatchAvgVelocity(minions[i]) * AlignWeight).GetClampedToMaxSize(AlignClamp);
			FVector Bounds = (AMinionManager::StayWithinBounds(minions[i])* BoundsWeight).GetClampedToMaxSize(BoundsClamp);

			if (i == 0) {
				GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Boid 0:"));
				GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, Cohesion.ToCompactString().Append("Cohesion"));
				GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, Avoid.ToCompactString().Append("Avoid"));
				GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, Align.ToCompactString().Append("Align"));
				GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, Bounds.ToCompactString().Append("Bounds"));

			}

			auto direction = (minions[i]->GetActorForwardVector()
				+ Cohesion + Avoid + Align + Bounds);
			minions[i]->MoveInDir(direction, MinionSpeed);
		}
	}
}


FVector AMinionManager::GetCentreOfMass() {
	auto output = FVector(0.0f, 0.0f, 0.0f);
	auto minionCount = 0;
	for (auto i = 0; i < minions.Num(); ++i) {
		if (minions[i]) {
			auto loc = minions[i]->GetActorLocation();
			output = output + loc;
			minionCount++;
		}
	}

	return output / (minionCount);
}

FVector AMinionManager::GetAverageVelocity() {
	auto output = FVector(0.0f, 0.0f, 0.0f);

	auto minionCount = 0;
	for (auto i = 0; i < minions.Num(); ++i) {
		if (minions[i]) {
			auto loc = minions[i]->GetVelocity();
			output = output + loc;
			minionCount++;
		}
	}

	return output / (minions.Num());
}

FVector AMinionManager::DistanceFromCenterOfMass(AMinion* minion) const {
	return (centreOfMass - minion->GetActorLocation());
}

FVector AMinionManager::AvoidOtherMinions(AMinion* minion) const {
	auto output = FVector(0.0f, 0.0f, 0.0f);

	for (auto i = 0; i < minions.Num(); ++i) {
		if (minions[i] && minions[i] != minion) {
			auto d = (minions[i]->GetActorLocation() - minion->GetActorLocation()).Size();
			if (d < AvioidMinionRange) {
				output = output - (minions[i]->GetActorLocation() - minion->GetActorLocation());
			}
		}
	}

	return output;
}

FVector AMinionManager::MatchAvgVelocity(AMinion* minion) const {
	return (averageVelocity - minion->GetActorForwardVector());
}

FVector AMinionManager::StayWithinBounds(AMinion* minion) const {
	auto output = FVector(0.0f, 0.0f, 0.0f);

	auto minionXStartDist = minion->GetActorLocation().X - (MinionSpawnBoundsStart.X + AvoidBoundsRange);
	auto minionXEndDist = minion->GetActorLocation().X - (MinionSpawnBoundsEnd.X + AvoidBoundsRange);
	if (minionXStartDist < 0) {
		output.X = -minionXStartDist;
	}
	else if (minionXEndDist > 0) {
		output.X = -minionXEndDist;
	}

	auto minionYStartDist = minion->GetActorLocation().Y - (MinionSpawnBoundsStart.Y + AvoidBoundsRange);
	auto minionYEndDist = minion->GetActorLocation().Y - (MinionSpawnBoundsEnd.Y + AvoidBoundsRange);
	if (minionYStartDist < 0) {
		output.Y = -minionYStartDist;
	}
	else if (minionYEndDist > 0) {
		output.Y = -minionYEndDist;
	}

	return output;
}