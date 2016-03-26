// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "Agent.h"


// Sets default values
AAgent::AAgent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAgent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAgent::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AAgent::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

UAction* AAgent::ChooseAction()
{
	for (auto Con : this->Considerations)
	{
		Con.GetDefaultObject()->Evaluate();
	}

	this->Considerations.Sort([](const TSubclassOf<UConsideration>& lhs, const TSubclassOf<UConsideration>& rhs)
	{
		return lhs.GetDefaultObject()->Score > rhs.GetDefaultObject()->Score;
	});

	return this->Considerations.GetData()->GetDefaultObject()->TheAction;
}
