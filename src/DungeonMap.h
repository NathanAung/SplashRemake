#pragma once
# include <Siv3D.hpp> // Siv3D v0.6.16

class DungeonMap
{
	Array<Grid<int32>> map;
	int32 mapFloor;

public:
	DungeonMap();
	void DrawMap(Texture mapTex, int32 mode);
private:
	int32 GetTileType(int32 x, int32 y);
	int32 GetTileCol(int32 x, int32 y);
	int32 GetTileStat(int32 x, int32 y);
	//int32 GetTileSomething(int32 x, int32 y);
};