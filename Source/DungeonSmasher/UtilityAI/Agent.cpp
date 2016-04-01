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
	if (++TickSincelastChoice >= ChooseEveryXTicks)
	{
		TickSincelastChoice = 0;
		if (CurrentAction->RunningTime > CurrentAction->MinRunTime)
		{
			auto chosen_action = this->ChooseAction();
			if (CurrentAction != chosen_action)
			{
				CurrentAction = chosen_action;
				CurrentAction->DoAction(this, static_cast<ADungeonSmasherGameMode*>(GetWorld()->GetAuthGameMode()));
			}
			GetWorld()->GetTimeSeconds();
		}
	}
	CurrentAction->ActionTick(this, static_cast<ADungeonSmasherGameMode*>(GetWorld()->GetAuthGameMode()), DeltaTime);


}

// Called to bind functionality to input
void AAgent::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

UAction* AAgent::ChooseAction()
{
	if (this->Considerations.Num() > 0) {
		for (auto Con : this->Considerations)
		{
			Con->Evaluate();
		}

		this->Considerations.Sort([](const UConsideration& lhs, const UConsideration& rhs)
		{
			return lhs.Score > rhs.Score;
		});

		return this->Considerations[0]->TheAction;
	}
	return this->CurrentAction;
}
