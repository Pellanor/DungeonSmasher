// Copyright 2015 Jason Campbell

#pragma once

#include "Object.h"
#include "Evaluator.h"
#include "UtilityCurve.h"
#include "UtilityCurveEvaluator.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONSMASHER_API UUtilityCurveEvaluator : public UObject, public IEvaluator
{
	GENERATED_BODY()
	
public:
	float Evaluate(float Val);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUtilityCurve* Curve;
	
};
