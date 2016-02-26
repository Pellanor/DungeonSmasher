// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "QuadraticCurve.h"
#include <cmath>

float UQuadraticCurve::Evaluate(float input) {
	float x = Normalize(input);
	float output = Slope * pow(x - YOffset, Exponent) + XOffset;
	if (output < 0)
		output = 0;
	else if (output > 1)
		output = 1;
	return output;
}


