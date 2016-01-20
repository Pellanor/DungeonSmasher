// Copyright 2015 Jason Campbell

#pragma once

#include "GameFramework/Character.h"
#include "ZoneOfControlCharacter.generated.h"

UCLASS()
class DUNGEONSMASHER_API AZoneOfControlCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZoneOfControlCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Zone of Control")
		float zone_str;
	
};
