// Copyright 2015 Jason Campbell

#pragma once

#include "Object.h"
#include "UtilityFunction.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONSMASHER_API UUtilityFunction : public UObject
{
	GENERATED_BODY()
	
public:
	// UE4 Doesn't allow properties to be interfaces, so I'll need to cast this when I use it.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	TArray<UObject*> Evaluators;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	TArray<float> Values;

	float Evaluate();
};
