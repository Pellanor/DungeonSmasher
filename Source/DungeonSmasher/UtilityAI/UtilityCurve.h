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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	float Slope;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	float Exponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	float XOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	float YOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	float InputMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	float InputMax;

	UFUNCTION(BlueprintCallable, Category = "Curve")
	virtual float Evaluate(float input) PURE_VIRTUAL(UtilityCurve::Evaluate, return -1;);

};
