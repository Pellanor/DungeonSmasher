// Copyright 2015 Jason Campbell

#pragma once

#include "Object.h"
#include "UtilityCurve.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONSMASHER_API UUtilityCurve : public UObject
{
	GENERATED_BODY()

protected:
	float Normalize(float input);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Slope;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Exponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float XOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float YOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InputMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InputMax;

	UFUNCTION(BlueprintCallable, Category = "Curve")
	virtual float Evaluate(float input) PURE_VIRTUAL(UtilityCurve::Evaluate, return -1;);

};
