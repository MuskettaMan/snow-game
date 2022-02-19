#pragma once
#include "surface.h"
#include "template.h"
using namespace Tmpl8;

/**
 * \brief Data for the tile map so it can display itself accordingly.
 */
class TileMapData
{
public:
	/**
	 * \brief Creates a new tile map data instance.
	 * \param texSize The size of the texture.
	 * \param tileSize The size of the tile.
	 * \param spacing The spacing between the tiles on the source texture.
	 * \param source The source texture.
	 */
	TileMapData(int texSize, int tileSize, const int spacing, Surface* source)
		: texSize(texSize),
		  tileSize(tileSize),
		  spacing(spacing),
		  source(source)
	{
	}

	/**
	 * \brief The size of the texture.
	 * \return The size of the texture.
	 */
	int GetTexSize();

	/**
	 * \brief The size of the tile.
	 * \return The size of the tile.
	 */
	int GetTileSize();

	/**
	 * \brief The spacing between the tiles on the source texture.
	 * \return The spacing between the tiles on the source texture.
	 */
	int GetSpacing();

	/**
	 * \brief The source texture.
	 * \return The source texture.
	 */
	Surface* GetSource();

private:
	/**
	 * \brief The size of the texture.
	 * \return The size of the texture.
	 */
	int texSize;

	/**
	 * \brief The size of the tile.
	 * \return The size of the tile.
	 */
	int tileSize;

	/**
	 * \brief The spacing between the tiles on the source texture.
	 * \return The spacing between the tiles on the source texture.
	 */
	int spacing;

	/**
	 * \brief The source texture.
	 * \return The source texture.
	 */
	Surface* source;
};

