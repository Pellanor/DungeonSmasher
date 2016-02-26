// Copyright 2015 Jason Campbell

#pragma once

#include "Object.h"
#include "Agent.h"

#include "Action.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class DUNGEONSMASHER_API UAction : public UObject
{
	GENERATED_BODY()
	
public:	
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Execute the action using this agent"))
	void DoAction(AAgent* ActingAgent);
	
	
};
