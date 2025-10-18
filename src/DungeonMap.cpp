#include "../stdafx.h"
#include "DungeonMap.h"

DungeonMap::DungeonMap()
{
	map =
	{
		{
		//	 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	0
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	1
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	2
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	3
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	4
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	5
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	6
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	7
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	8
			{0,0,0,0,0,0,0x01000009,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	9
			{0,0,0,0,0,0x00000101,0x01010104,0x00000101,0x00000101,0x00000101,0x00000101,0,0,0,0,0,0,0,0,0},	//	0
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	1
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	2
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	3
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	4
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	5
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	6
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	7
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	8
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	9
		},
		// {
		// //	 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	0
		// 	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	1
		// 	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	2
		// 	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	3
		// 	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	4
		// 	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	5
		// 	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	6
		// 	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	7
		// 	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	8
		// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},	//	9
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	0
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	1
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	2
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	3
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	4
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	5
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	6
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},	//	7
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	8
		// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},	//	9
		// },
	};
}

// Get Tile Type (Lower 8 bits)
int32 DungeonMap::GetTileType(int32 x, int32 y) {
	return map[mapLayer][y][x] & 0xFF;  // Mask the lower 8 bits
}

// Get Collider (Next 8 bits)
int32 DungeonMap::GetTileCol(int32 x, int32 y) {
	return (map[mapLayer][y][x] >> 8) & 0xFF;  // Shift right by 8 and mask the next 8 bits
}

// Get Tile Status (Next 8 bits)
int32 DungeonMap::GetTileStat(int32 x, int32 y) {
	return (map[mapLayer][y][x] >> 16) & 0xFF;  // Shift right by 16 and mask the next 8 bits
}

// Get the pair index of the gimmick tiles (e.g. button and door) (Upper 8 bits)
int32 DungeonMap::GetTilePairIdx(int x, int y) {
    return (map[mapLayer][y][x] >> 24) & 0xFF;  // Shift right by 24 and mask the upper 8 bits
}

void DungeonMap::DrawMap(Texture& mapTex, int32 mode)
{
	for (int32 y : step(mapHeight))
	{
		for (int32 x : step(mapWidth))
		{
			Vec2 pos(x * tileWidth, y * tileHeight);
			int32 tileType = GetTileType(x, y);
			int32 tileStat = GetTileStat(x, y);
			if (mode == 0)	// all first tile
				mapTex(0, 0, tileWidth, tileHeight).draw(pos);
			else if (mode == 1)	// draw correct tiles
				mapTex(tileType * tileWidth, 0, tileWidth, tileHeight).draw(pos);
			else if (mode == 2 && tileType == 1) // make tile 1 black
				mapTex(tileWidth * 1, 0, tileWidth, tileHeight).draw(pos, ColorF{ 0.0 });
		}
	}
}

Array<P2Body> DungeonMap::CreateMapCol(P2World& pWorld)
{
	Array<P2Body> bodies;
	for (int32 y : step(mapHeight))
	{
		bool tileExist = false;
		Vec2 existPos;
		int tileCount = 0;
		for (int32 x : step(mapWidth))
		{
			Vec2 pos(x * tileWidth, y * tileHeight+ tileHeight/2);
			int32 tileType = GetTileType(x, y);
			int32 tileCol = GetTileCol(x, y);
			int32 tileStat = GetTileStat(x, y);
			int32 tileObs = GetTilePairIdx(x, y);
			
			if(tileType == 1 && tileCol == 1){
				if(tileExist){
					tileCount++;
				}
				else{
					existPos = pos;
					tileExist = true;
					tileCount++;
				}
			}
			else if(tileStat == 1 && tileCol == 1){
				if(tileExist){
					existPos.x += (tileWidth/2) * tileCount;
					bodies << pWorld.createRect(P2Static, existPos, SizeF{tileWidth * tileCount, tileHeight});
					Print << U"Tiles placed " << tileCount;
					Print << U"body placed at " << existPos;
					Print << U"body array size " << bodies.size();
					tileExist = false;
					tileCount = 0;
					gimmickPairColPos << Vec2(x, y);
				}
				
				pos.x += tileWidth/2;
				bodies << pWorld.createRect(P2Static, pos, SizeF{tileWidth, tileHeight});
				
				Print << U"door placed at " << pos;
				Print << U"body array size " << bodies.size();

			}
			else if(tileExist){
				existPos.x += (tileWidth/2) * tileCount;
				bodies << pWorld.createRect(P2Static, existPos, SizeF{tileWidth * tileCount, tileHeight});
				Print << U"Tiles placed " << tileCount;
				Print << U"body placed at " << existPos;
				Print << U"body array size " << bodies.size();
				tileExist = false;
				tileCount = 0;
			}
			else{
				existPos = pos;
			}
		}

		if(tileExist){
			existPos.x += (tileWidth/2) * tileCount;
			bodies << pWorld.createRect(P2Static, existPos, SizeF{tileWidth * tileCount, tileHeight});
			Print << U"Tiles placed " << tileCount;
			Print << U"body placed at " << existPos;
			tileExist = false;
			tileCount = 0;
		}
	}

	return bodies;
}

void DungeonMap::DrawMapCol(Array<P2Body>& mapColArr){
	// Draw all bodies
	for (const auto& body : mapColArr)
	{
		body.draw(HSV{ body.id() * 10.0 });
	}
}

Array<DungeonMap::Gimmick> DungeonMap::CreateMapGimmicks(){
	Array<Gimmick> gimmicks;

	for (int32 y : step(mapHeight))
	{
		for (int32 x : step(mapWidth))
		{
			Vec2 pos(x * tileWidth, y * tileHeight);
			int32 tileType = GetTileType(x, y);
			int32 tileStat = GetTileStat(x, y);
			int32 tilePairIdx = GetTilePairIdx(x, y);
			
			if(tileType == 9){
				gimmicks << Gimmick(0, x, y, tileWidth, tilePairIdx);
				Print << U"gimmick placed at " << pos;
			}
		}
	}

	return gimmicks;
}


void DungeonMap::UpdateMapGimmicks(Array<Gimmick>& gimmickArr, Array<P2Body>& mapColArr, P2Body& player){
	const Circle c{player.getPos().x, player.getPos().y, tileWidth/2};
	for(int i = 0; i < gimmickArr.size(); i++){
		Gimmick& gimmick = gimmickArr[i];

		if(gimmick.collider.intersects(c)){
			//Print << U"intersecting";
			
		}

		//Print << player.getPos().x;
		//Print << player.getPos().y;

		gimmick.collider.draw(Palette::Cyan);
		c.draw(Palette::Green);
	}
}


void DungeonMap::ActivateGimmick(Gimmick& gimmick, Array<P2Body>& mapColArr){
	
}

void DungeonMap::LinkGimmick(Array<Gimmick>& gimmickArr){
	for(int i = 0; i < gimmickArr.size(); i++){
		for(int j = 0; j < gimmickPairColPos.size(); j++){
			int32 tilePairIdx = GetTilePairIdx(gimmickPairColPos[j].x, gimmickPairColPos[j].y);
			if(gimmickArr[i].pairColIndx == tilePairIdx){
				gimmickArr[i].pairColX = gimmickPairColPos[j].x;
				gimmickArr[i].pairColY = gimmickPairColPos[j].y;
				Print << U"gimmick linked for " << tilePairIdx;
			}
		}
	}
}