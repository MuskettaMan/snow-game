#pragma once
#include <random>

#include "IPlacementGenerator.h"

class RandomPlacementGenerator : public IPlacementGenerator
{
public:
	vec2 GetPlacement(std::vector<vec2>* positions) const override;
};

