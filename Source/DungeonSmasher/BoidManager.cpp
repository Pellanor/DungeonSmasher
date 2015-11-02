// Based on http://www.appzeit.com/unrealengine/277-unrealengine-4-boids-implementation-in-c-pt1-overview 

#include "DungeonSmasher.h"
#include "BoidManager.h"


// Sets default values
ABoidManager::ABoidManager() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay() {
	Super::BeginPlay();
	World = GetWorld();
	FVector thisSpawnPos;

	for (int32 i = 0; i < NumberOfBoids; i++)
	{
		thisSpawnPos.X = FMath::RandRange(SpawnBoundsStart.X, SpawnBoundsEnd.X);
		thisSpawnPos.Y = FMath::RandRange(SpawnBoundsStart.Y, SpawnBoundsEnd.Y);
		thisSpawnPos.Z = FMath::RandRange(SpawnBoundsStart.Z, SpawnBoundsEnd.Z);

		ABoid* spawnedBoid = World->SpawnActor<ABoid>(ABoid::StaticClass(), thisSpawnPos, FRotator(0.0f));
		boids.Add(spawnedBoid);
	}
}

// Called every frame
void ABoidManager::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );

	centreOfMass = GetCentreOfMass();
	averageVelocity = GetAverageVelocity();

	for (auto i = 0; i < boids.Num(); ++i) {
		boids[i]->velocity = (boids[i]->velocity
			+ (ABoidManager::Rule1(boids[i]) * CohesionWeight).ClampMaxSize(CohesionClamp)
			+ (ABoidManager::Rule2(boids[i]) * AvoidWeight).ClampMaxSize(AvoidClamp)
			+ (ABoidManager::Rule3(boids[i]) * AlignWeight).ClampMaxSize(AlignClamp)
			+ (ABoidManager::Rule4(boids[i])* BoundsWeight).ClampMaxSize(BoundsClamp)
			);
	}
}

FVector ABoidManager::GetCentreOfMass() {
	auto output = FVector(0.0f, 0.0f, 0.0f);

	for (auto i = 0; i < boids.Num(); ++i) {
		output = output + boids[i]->GetActorLocation();
	}

	return output / (boids.Num());
}

FVector ABoidManager::GetAverageVelocity() {
	auto output = FVector(0.0f, 0.0f, 0.0f);

	for (auto i = 0; i < boids.Num(); ++i) {

		output = output + boids[i]->velocity;
	}

	return output / (boids.Num());
}

FVector ABoidManager::Rule1(ABoid* boid) {
	return (centreOfMass - boid->GetActorLocation());
}

FVector ABoidManager::Rule2(ABoid* boid) {
	auto output = FVector(0.0f, 0.0f, 0.0f);

	for (auto i = 0; i < boids.Num(); ++i) {
		if (boids[i] != boid) {
			float d = (boids[i]->GetActorLocation() - boid->GetActorLocation()).Size();
			if (d < AvoidBoidRange) {
				output = output - (boids[i]->GetActorLocation() - boid->GetActorLocation());
			}
		}
	}

	return output;
}

FVector ABoidManager::Rule3(ABoid* boid) {
	return (averageVelocity - boid->velocity);
}

FVector ABoidManager::Rule4(ABoid* boid) {
	auto output = FVector(0.0f, 0.0f, 0.0f);

	if (boid->GetActorLocation().X < SpawnBoundsStart.X) {
		output.X = AvoidBoundsRange;
	}
	else if (boid->GetActorLocation().X > SpawnBoundsEnd.X) {
		output.X = -AvoidBoundsRange;
	}

	if (boid->GetActorLocation().Y < SpawnBoundsStart.Y) {
		output.Y = AvoidBoundsRange;
	}
	else if (boid->GetActorLocation().Y > SpawnBoundsEnd.Y) {
		output.Y = -AvoidBoundsRange;
	}

	if (boid->GetActorLocation().Z < SpawnBoundsStart.Z) {
		output.Z = AvoidBoundsRange;
	}
	else if (boid->GetActorLocation().Z > SpawnBoundsEnd.Z) {
		output.Z = -AvoidBoundsRange;
	}

	return output;
}