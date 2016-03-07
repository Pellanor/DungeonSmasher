// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "UCurveEvaluator.h"


float UUCurveEvaluator::Evaluate(float Val) {
	return Curve->GetFloatValue(Val);
}

