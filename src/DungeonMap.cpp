#include "../stdafx.h"
#include "DungeonMap.h"

DungeonMap::DungeonMap() : mapFloor(0)
{
	map =
	{
		{
			//	 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	0
				{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	1
				{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	2
				{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	3
				{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	4
				{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	5
				{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	6
				{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	7
				{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	8
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},	//	9
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	0
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	1
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	2
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	3
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	4
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	5
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	6
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	7
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	8
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	9
			},
	};
}

// Get Tile Type (Lower 8 bits)
int32 DungeonMap::GetTileType(int32 x, int32 y) {
    return map[mapFloor][y][x] & 0xFF;  // Mask the lower 8 bits
}

// Get Collider (Next 8 bits)
int32 DungeonMap::GetTileCol(int32 x, int32 y) {
    return (map[mapFloor][y][x] >> 8) & 0xFF;  // Shift right by 8 and mask the next 8 bits
}

// Get Tile Status (Next 8 bits)
int32 DungeonMap::GetTileStat(int32 x, int32 y) {
    return (map[mapFloor][y][x] >> 16) & 0xFF;  // Shift right by 16 and mask the next 8 bits
}

// // Get Additional Info (Upper 8 bits)
// int32 DungeonMap::GetTileSomething(int x, int y) {
//     return (map[y][x] >> 24) & 0xFF;  // Shift right by 24 and mask the upper 8 bits
// }

void DungeonMap::DrawMap(Texture mapTex, int32 mode)
{
	for (int32 y : step(20))
	{
		for (int32 x : step(20))
		{
			Vec2 pos(x * 32, y * 32);
			int32 tileType = GetTileType(x, y);
			int32 tileStat = GetTileStat(x, y);
			if (mode == 0)	// all first tile
				mapTex(0, 0, 32, 32).draw(pos);
			else if (mode == 1)	// draw correct tiles
				mapTex(tileType * 32, 0, 32, 32).draw(pos);
		}
	}
}
