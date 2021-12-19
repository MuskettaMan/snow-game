#include "TileMapData.h"

int TileMapData::GetTexSize()
{
	return texSize;
}

int TileMapData::GetTileSize()
{
	return tileSize;
}

int TileMapData::GetSpacing()
{
	return spacing;
}

Surface* TileMapData::GetSource()
{
	return source;
}
