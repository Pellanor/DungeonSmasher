// Copyright 2015 Jason Campbell

#pragma once

#include "GameFramework/Actor.h"
#include "Minion.h"
#include "MinionManager.generated.h"

UCLASS()
class DUNGEONSMASHER_API AMinionManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMinionManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	FVector GetCentreOfMass();
	FVector GetAverageVelocity();
	FVector DistanceFromCenterOfMass(AMinion* minion) const;
	FVector AvoidOtherMinions(AMinion* minion) const;
	FVector MatchAvgVelocity(AMinion* minion) const;
	FVector StayWithinBounds(AMinion* minion) const;
private:
	UWorld*  World;
	TArray<AMinion *> minions;
	FVector centreOfMass;
	FVector averageVelocity;

	UPROPERTY(EditAnywhere)
		FVector MinionSpawnBoundsStart;
	UPROPERTY(EditAnywhere)
		FVector MinionSpawnBoundsEnd;
	UPROPERTY(EditAnywhere)
		int32 InitialMinionCount;
	UPROPERTY(EditAnywhere)
		int32 MinionSpeed;

	UPROPERTY(EditAnywhere, Category = BoidAttributes)
		float AvioidMinionRange;
	UPROPERTY(EditAnywhere, Category = BoidAttributes)
		float AvoidBoundsRange;

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
};
