#pragma once
#include "surface.h"
#include "template.h"
using namespace Tmpl8;

class TileMapData
{
public:
	TileMapData(int texSize, int tile_size, const int spacing, Surface* source)
		: texSize(texSize),
		  tileSize(tile_size),
		  spacing(spacing),
		  source(source)
	{
	}
	int GetTexSize();
	int GetTileSize();
	int GetSpacing();
	Surface* GetSource();

private:
	int texSize;
	int tileSize;
	int spacing;
	Surface* source;
};

