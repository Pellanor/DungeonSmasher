// Copyright 2015 Jason Campbell

#include "DungeonSmasher.h"
#include "Consideration.h"


float UConsideration::Evaluate() {
	this->Score = this->TheUtilityFunction->Evaluate();
	return this->Score;
}
