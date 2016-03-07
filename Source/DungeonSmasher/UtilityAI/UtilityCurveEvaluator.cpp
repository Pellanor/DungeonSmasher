// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "UtilityCurveEvaluator.h"


float UUtilityCurveEvaluator::Evaluate(float Val) {
	return Curve->Evaluate(Val);
}

