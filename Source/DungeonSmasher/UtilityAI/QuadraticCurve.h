// Copyright 2015 Jason Campbell

#pragma once

#include "UtilityAI/UtilityCurve.h"
#include "QuadraticCurve.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONSMASHER_API UQuadraticCurve : public UUtilityCurve
{
	GENERATED_BODY()
	
public:
	float Evaluate(float input);
	
	
};
