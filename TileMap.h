#pragma once
#include "surface.h"
#include "TileMapData.h"
#include "IDrawable.h"

using namespace Tmpl8;

class TileMap : public IDrawable
{
public:
	static const int ROWS = 8;
	static const int COLS = 13;
	static const int DATA_AMOUNT = 3;

	TileMap(char map[ROWS][COLS * DATA_AMOUNT], TileMapData& tileMapData);
	void Draw(Surface* screen);

private:
	char map[ROWS][COLS * DATA_AMOUNT];
	TileMapData& tileMapData;

	void DrawTile(int tx, int ty, Surface* screen, int x, int y);
};

