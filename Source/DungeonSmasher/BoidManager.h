// Based on http://www.appzeit.com/unrealengine/277-unrealengine-4-boids-implementation-in-c-pt1-overview 

#pragma once

#include "GameFramework/Actor.h"
#include "Boid.h"
#include "BoidManager.generated.h"

UCLASS()
class DUNGEONSMASHER_API ABoidManager : public AActor
{
	GENERATED_BODY()

private:
	UWorld*  World;

	UPROPERTY(EditAnywhere)
		FVector SpawnBoundsStart;
	UPROPERTY(EditAnywhere)
		FVector SpawnBoundsEnd;
	UPROPERTY(EditAnywhere)
		int32 NumberOfBoids;

	UPROPERTY(EditAnywhere, Category = BoidAttributes)
		float AvoidBoidRange;
	UPROPERTY(EditAnywhere, Category = BoidAttributes)
		float AvoidBoundsRange;
	UPROPERTY(EditAnywhere, Category = BoidAttributes)
		float BoidSpeedMultiplier;
	UPROPERTY(EditAnywhere)
		int32 FrameSkip;

	UPROPERTY(EditAnywhere, Category = RuleWeights)
		float CohesionWeight;
	UPROPERTY(EditAnywhere, Category = RuleWeights)
		float CohesionClamp;
	UPROPERTY(EditAnywhere, Category = RuleWeights)
		float AvoidWeight;
	UPROPERTY(EditAnywhere, Category = RuleWeights)
		float AvoidClamp;
	UPROPERTY(EditAnywhere, Category = RuleWeights)
		float AlignWeight;
	UPROPERTY(EditAnywhere, Category = RuleWeights)
		float AlignClamp;
	UPROPERTY(EditAnywhere, Category = RuleWeights)
		float BoundsWeight;
	UPROPERTY(EditAnywhere, Category = RuleWeights)
		float BoundsClamp;

	FVector centreOfMass;
	FVector averageVelocity;

	TArray<ABoid *> boids;

	ACharacter* myCharacter;

public:	
	// Sets default values for this actor's properties
	ABoidManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FVector GetCentreOfMass();
	FVector GetAverageVelocity();

	FVector Rule1(ABoid* boid);
	FVector Rule2(ABoid* boid);
	FVector Rule3(ABoid* boid);
	FVector Rule4(ABoid* boid);
	
};
