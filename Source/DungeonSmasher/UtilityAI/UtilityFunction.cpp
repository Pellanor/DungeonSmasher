// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "UtilityFunction.h"
#include "Evaluator.h"


float UUtilityFunction::Evaluate() {
	float modificationFactor = 1 - (1 / Evaluators.Num());
	float score = 1.0;
	for (int32 i = 0; i < Evaluators.Num(); i++) {
		if (Evaluators[i]->GetClass()->ImplementsInterface(UEvaluator::StaticClass()))
		{
			float result = IEvaluator::Execute_Evaluate(Evaluators[i], Values[i]);
			// Adjust the result so that it doesn't drop as quickly with the number of evaluators.
			score *= result + result * ((1 - result) * modificationFactor);
		}
	}
	return score;
}

