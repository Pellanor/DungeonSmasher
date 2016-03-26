// Copyright 2015 Jason Campbell

#pragma once

#include "GameFramework/Character.h"
#include "Consideration.h"
#include "Action.h"
#include "Agent.generated.h"

UCLASS()
class DUNGEONSMASHER_API AAgent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAgent();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector GoalLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray< TSubclassOf<UConsideration> > Considerations;

	UAction* ChooseAction();

};
