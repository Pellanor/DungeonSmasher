// Copyright 2015 Jason Campbell

#pragma once

#include "Object.h"
#include "Action.h"
#include "Evaluator.h"
#include "Consideration.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONSMASHER_API UConsideration : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Action", ExposeOnSpawn = true))
	UAction* TheAction;

	// UE4 Doesn't allow properties to be interfaces, so I'll need to cast this when I use it.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Evaluator", ExposeOnSpawn = true))
	UObject* TheEvaluator;
	
};
