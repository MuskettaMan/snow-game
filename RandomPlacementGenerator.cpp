#include "RandomPlacementGenerator.h"

RandomPlacementGenerator::RandomPlacementGenerator(const Character& character) : character(character)
{
}

vec2 RandomPlacementGenerator::GetPlacement(std::vector<vec2>* positions) const
{
	vec2 position;
	float distance;
	do
	{
		position = { static_cast<float>(rand() % (ScreenWidth - 68) + 68), static_cast<float>(rand() % (ScreenHeight - 68) + 68) };
		distance = vec2::distance(position, character.GetPosition());
	} while (distance < 100);
	return position;
}
