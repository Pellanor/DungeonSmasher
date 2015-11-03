//
// Based on http://www.appzeit.com/unrealengine/277-unrealengine-4-boids-implementation-in-c-pt1-overview 

#pragma once

#include "GameFramework/Actor.h"
#include "Boid.generated.h"

UCLASS()
class DUNGEONSMASHER_API ABoid : public AActor
{
	GENERATED_BODY()
	UStaticMeshComponent* mesh;
	
public:	
	// Sets default values for this actor's properties
	ABoid();
	ABoid(const class FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Boid's current velocity
	FVector velocity;
	
};
