#pragma once
#include "surface.h"
#include "TileMapData.h"
#include "IDrawable.h"

using namespace Tmpl8;

/**
 * \brief Defines a tilemap that can be used to draw tiles on.
 */
class TileMap : public IDrawable
{
public:
	/**
	 * \brief The amount of rows in the map.
	 */
	static const int ROWS = 8;

	/**
	 * \brief The amount columns in the map.
	 */
	static const int COLS = 13;

	/**
	 * \brief The amount of data per tile.
	 */
	static const int DATA_AMOUNT = 3;

	/**
	 * \brief Creates a new tile map.
	 * \param map The map of data to be used to draw the tile map.
	 * \param tileMapData All the data for the tile map.
	 */
	TileMap(char map[ROWS][COLS * DATA_AMOUNT], TileMapData& tileMapData);

	/**
	 * \brief Draws all the tiles to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen);

private:
	/**
	 * \brief The data of the tiles to draw.
	 */
	char map[ROWS][COLS * DATA_AMOUNT];

	/**
	 * \brief The data for the tile map.
	 */
	TileMapData& tileMapData;

	/**
	 * \brief Draws a tile at a certain position.
	 * \param tx Tile X coordinate.
	 * \param ty Tile Y coordinate.
	 * \param screen The screen to draw to.
	 * \param x Screen X coordinate.
	 * \param y Screen Y coordinate.
	 */
	void DrawTile(int tx, int ty, Surface* screen, int x, int y);
};

