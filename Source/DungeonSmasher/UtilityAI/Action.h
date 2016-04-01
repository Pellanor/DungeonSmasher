// Copyright 2015 Jason Campbell

#pragma once

#include "Object.h"
#include "DungeonSmasherGameMode.h"

#include "Action.generated.h"

//Forward declaring as the Action needs to have access to the Agent.
class AAgent;

/**
 * 
 */
UCLASS(Blueprintable)
class DUNGEONSMASHER_API UAction : public UObject
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Min Run Time", ExposeOnSpawn = true))
	float MinRunTime = 0;

	UPROPERTY(BlueprintReadOnly, Meta = (DisplayName = "Running Time"))
	float RunningTime = 1000;

	UPROPERTY(BlueprintReadOnly, Meta = (DisplayName = "Last Run Time"))
	float LastRunTime = 0;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Execute the action using this agent"))
	void DoAction(AAgent* ActingAgent, ADungeonSmasherGameMode* CurrentGameMode);
	
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Tick the action using this agent"))
	void ActionTick(AAgent* ActingAgent, ADungeonSmasherGameMode* CurrentGameMode, float DeltaTime);

	void DoAction_Implementation(AAgent* ActingAgent, ADungeonSmasherGameMode* CurrentGameMode);

	void ActionTick_Implementation(AAgent* ActingAgent, ADungeonSmasherGameMode* CurrentGameMode, float DeltaTime);
};
