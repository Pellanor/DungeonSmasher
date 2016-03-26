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
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Execute the action using this agent"))
	void DoAction(AAgent* ActingAgent, ADungeonSmasherGameMode* CurrentGameMode);
	
	
};
