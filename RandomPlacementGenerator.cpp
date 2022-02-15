#include "RandomPlacementGenerator.h"

#include <ctime>

#include "TileMap.h"

struct GridPosition
{
	int x;
	int y;
};

RandomPlacementGenerator::RandomPlacementGenerator(const Character& character) : character(character)
{
	srand(time(NULL));
}

vec2 RandomPlacementGenerator::GetPlacement() const
{
	std::vector<GridPosition> filteredPositions;
	GridPosition grid[TileMap::COLS][TileMap::ROWS];
	for (int i = 0; i < TileMap::COLS; ++i)
	{
		for (int j = 0; j < TileMap::ROWS; ++j)
		{
			GridPosition pos{ i * 64, j * 64 };
			if (vec2::distance(vec2(pos.x, pos.y), character.GetPosition()) > radius)
			{
				filteredPositions.push_back(pos);
			}
		}
	}

	GridPosition pos = filteredPositions[rand() % filteredPositions.size()];

	return vec2(pos.x, pos.y);
}
