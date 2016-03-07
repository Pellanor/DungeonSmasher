// Copyright 2015 Jason Campbell

#pragma once

#include "Interface.h" 
#include "Evaluator.generated.h"

/**
 * 
 */
UINTERFACE()
class DUNGEONSMASHER_API UEvaluator : public UInterface
{
	GENERATED_UINTERFACE_BODY()
	
};


class DUNGEONSMASHER_API IEvaluator : public IInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	// To be able to access this using IEvaluator::Execute_Evaluate() it needs to be a BlueprintImplementableEvent
	// TO be a BlueprintImplementableEvent it cannot be virtual.
	UFUNCTION(BlueprintImplementableEvent)
	float Evaluate(float Val);
};

