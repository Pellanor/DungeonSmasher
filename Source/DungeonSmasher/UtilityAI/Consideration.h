// Copyright 2015 Jason Campbell

#pragma once

#include "Object.h"
#include "Action.h"
#include "UtilityFunction.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Utility Function", ExposeOnSpawn = true))
	UUtilityFunction* TheUtilityFunction;

	UPROPERTY(BlueprintReadOnly)
	float Score = 0.0f;
	
	float Evaluate();
};
