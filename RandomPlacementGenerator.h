#pragma once
#include <random>

#include "Character.h"
#include "IPlacementGenerator.h"

class RandomPlacementGenerator : public IPlacementGenerator
{
public:
	RandomPlacementGenerator(const Character& character);
	vec2 GetPlacement(std::vector<vec2>* positions) const override;

private:
	const Character& character;

};

