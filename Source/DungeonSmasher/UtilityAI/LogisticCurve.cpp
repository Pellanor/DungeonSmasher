// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "LogisticCurve.h"
#include <cmath>

const double E = 2.71828182845904523536;

float ULogisticCurve::Evaluate(float input) {
	float x = Normalize(input);
	float output = Exponent / (pow(1000 * E*Slope, -x + YOffset) + 1 + XOffset);
	if (output < 0)
		output = 0;
	else if (output > 1)
		output = 1;
	return output;
}


