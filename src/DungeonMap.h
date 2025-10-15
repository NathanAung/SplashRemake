#pragma once
# include <Siv3D.hpp> // Siv3D v0.6.16

class DungeonMap
{
	Array<Grid<int32>> map;
	int32 mapFloor;

public:
	enum mapModes{
		bg,
		normal,
		firstOnly,
	};
	DungeonMap();
	void DrawMap(Texture mapTex, int32 mode);	// draw the map on the screen
	Array<P2Body> CreateMapCol(P2World pWorld);	// create colliders for the map
	void DrawMapCol(Array<P2Body>& mapColArr);	// draw map for debugging

private:
	int32 const tileWidth = 32;		// in pixels
	int32 const tileHeight = 32;
	int32 mapWidth = 20;	// in tiles
	int32 mapHeight = 20;
	int32 GetTileType(int32 x, int32 y);
	int32 GetTileCol(int32 x, int32 y);
	int32 GetTileStat(int32 x, int32 y);
	//int32 GetTileSomething(int32 x, int32 y);
};