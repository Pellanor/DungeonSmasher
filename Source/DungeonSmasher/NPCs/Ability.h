// Copyright 2015 Jason Campbell

#pragma once

#include "Components/ActorComponent.h"
#include "Ability.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONSMASHER_API UAbility : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbility();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// Call to use the ability
	UFUNCTION()
	virtual void Use();

	// Call to see how much threat the ability represents
	UFUNCTION()
	virtual float Threat( FVector DistanceToTarget);

	UPROPERTY(EditAnywhere, Category = Properties)
	float range;

	UPROPERTY(EditAnywhere, Category = Properties)
	float damage;

	UPROPERTY(EditAnywhere, Category = Properties)
	float cooldown;
	
	bool onCD;
	float cdRemaining;
};
