#pragma once
# include <Siv3D.hpp> // Siv3D v0.6.16

class DungeonMap
{
	Array<Grid<int32>> map;
	int32 mapLayer;

	


public:
	struct Gimmick{
		int type = 0;
		int colSize = 32;
		int posX = 0;
		int posY = 0;
		bool activated = false;
		int pairColIndx = 0;
		
		Rect collider;

		Gimmick(int t, int x, int y, int size){
			type = t;
			posX = x;
			posY = y;
			colSize = size;

			collider = Rect{x, y, size};
		}
	};
	enum mapModes{
		bg,
		normal,
		firstOnly,
	};
	DungeonMap();
	void DrawMap(Texture& mapTex, int32 mode);	// draw the map on the screen
	Array<P2Body> CreateMapCol(P2World& pWorld);	// create colliders for the map
	void DrawMapCol(Array<P2Body>& mapColArr);	// draw map for debugging
	Array<Gimmick> CreateMapGimmicks();
	void UpdateMapGimmicks(Array<Gimmick>& gimmickArr, Array<P2Body>& mapColArr, P2Body& player);
	void LinkGimmick();
	void ActivateGimmick(Gimmick& gimmick, Array<P2Body>& mapColArr);

private:
	int32 const tileWidth = 32;		// in pixels
	int32 const tileHeight = 32;
	int32 mapWidth = 20;	// in tiles
	int32 mapHeight = 20;
	int32 GetTileType(int32 x, int32 y);
	int32 GetTileCol(int32 x, int32 y);
	int32 GetTileStat(int32 x, int32 y);
	int32 GetTilePairIdx(int32 x, int32 y);
};