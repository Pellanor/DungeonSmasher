// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "UtilityCurve.h"


float UUtilityCurve::Normalize(float input) {
	if (input < InputMin)
		input = InputMin;
	else if(input > InputMax)
		input = InputMax;
	return input;
}

