// Copyright 2015 Jason Campbell

#pragma once

#include "UtilityAI/UtilityCurve.h"
#include "LogisticCurve.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONSMASHER_API ULogisticCurve : public UUtilityCurve
{
	GENERATED_BODY()
	
public:
	float Evaluate(float input);
	
};
