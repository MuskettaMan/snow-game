#pragma once
#include <random>

#include "Character.h"
#include "IPlacementGenerator.h"

class RandomPlacementGenerator : public IPlacementGenerator
{
public:
	RandomPlacementGenerator(const Character& character);
	vec2 GetPlacement() const override;

private:
	const Character& character;
	int radius = 150;
};

