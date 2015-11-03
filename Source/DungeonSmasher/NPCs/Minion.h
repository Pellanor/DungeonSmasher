// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Minion.generated.h"

UCLASS()
class DUNGEONSMASHER_API AMinion : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMinion();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	void MoveInDir(FVector Direction, float Magnitude);

	FColor color = FColor(255, 0, 0);

private:
	FVector Destination;
};
