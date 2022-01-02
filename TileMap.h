#pragma once
#include "surface.h"
#include "TileMapData.h"
#include "IDrawable.h"

class TileMap : public IDrawable
{
public:
	static const int ROWS = 8;
	static const int COLS = 13;
	static const int DATA_AMOUNT = 3;

	TileMap(char map[ROWS][COLS * DATA_AMOUNT], TileMapData& tileMapData);
	void Draw(Tmpl8::Surface* screen);

private:
	char map[ROWS][COLS * DATA_AMOUNT];
	TileMapData& tileMapData;

	void DrawTile(int tx, int ty, Tmpl8::Surface* screen, int x, int y);
};

