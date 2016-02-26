// Copyright 2015 Jason Campbell

#pragma once

#include "Object.h"
#include "Evaluator.h"

#include "UCurveEvaluator.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONSMASHER_API UUCurveEvaluator : public UObject, public IEvaluator
{
	GENERATED_BODY()
	
public:
	void Evaluate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* Curve;
};
