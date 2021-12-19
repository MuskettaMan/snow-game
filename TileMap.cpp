#include "TileMap.h"

TileMap::TileMap(char map[ROWS][COLS * DATA_AMOUNT], TileMapData& tileMapData) :
	map(),
	tileMapData(tileMapData)
{
	for (int y = 0; y < ROWS; y++)
		for (int x = 0; x < COLS * DATA_AMOUNT; x++)
			this->map[y][x] = map[y][x];
}

void TileMap::Draw(Surface* screen)
{
	for (int y = 0; y < ROWS; y++)
	{
		for (int x = 0; x < COLS; x++)
		{
			int tx = map[y][x * DATA_AMOUNT] - 'a', ty = map[y][x * DATA_AMOUNT + 1] - 'a';
			DrawTile(tx, ty, screen, x * tileMapData.GetTileSize(), y * tileMapData.GetTileSize());
		}
	}
}

void TileMap::DrawTile(int tx, int ty, Tmpl8::Surface* screen, int x, int y)
{
	Pixel* src = tileMapData.GetSource()->GetBuffer() + tx * (tileMapData.GetTileSize() + tileMapData.GetSpacing()) + ty * (tileMapData.GetTileSize() + tileMapData.GetSpacing()) * tileMapData.GetTexSize();
	Pixel* dst = screen->GetBuffer() + x + y * screen->GetWidth();
	for (int i = 0; i < tileMapData.GetTileSize(); i++, src += tileMapData.GetTexSize(), dst += screen->GetWidth())
		for (int j = 0; j < tileMapData.GetTileSize(); j++)
			dst[j] = src[j];
}
