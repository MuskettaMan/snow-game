#include "RandomPlacementGenerator.h"

vec2 RandomPlacementGenerator::GetPlacement(std::vector<vec2>* positions) const
{
	return { static_cast<float>(rand() % (ScreenWidth - 68) + 68), static_cast<float>(rand() % (ScreenHeight - 68) + 68) };
}
