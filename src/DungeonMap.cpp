#include "DungeonMap.h"

/*
	MAP TILE DATA:
	00 - 07 bits: sprite index on texture
	08 - 15 bits: type: 0 - normal, 1 - wall, 2 - obstacle, 3 - gimmick
	16 - 23 bits: status: 0 - none, 1 - activated
	24 - 31 bits: pair index for linking gimmicks and obstacles  
*/

DungeonMap::DungeonMap() {
    // // Initialize map (20×20)
    // map.resize(Width, Height);

    // for (int y = 0; y < Height; y++) {
    //     for (int x = 0; x < Width; x++) {
    //         int32 tile = 0;
    //         SetSprite(tile, 0);  // sprite index
    //         SetType(tile, 0);    // normal
    //         SetStatus(tile, 0);  // unused
    //         SetPairID(tile, 0);  // none
    //         map[y][x] = tile;
    //     }
    // }

    // // Example gimmick and obstacle link:
    // // Gimmick: type=9 at (5,9), pairID=1
    // // Obstacle: type=1, collider=1, status=1, pairID=1
    // SetSprite(map[9][5], 9);
    // SetType(map[9][5], TileType::gimmick);
    // SetPairID(map[9][5], 1);

    // SetSprite(map[10][6], 4);
    // SetType(map[10][6], TileType::obstacle);
	// SetPairID(map[10][6], 1);

	// SetSprite(map[11][6], 1);
	// SetType(map[11][6], 1);

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
			{0,0,0,0,0,0,0x01000309,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	9
			{0,0,0,0,0,0x00000101,0x01000204,0x00000101,0,0,0,0,0,0,0,0,0,0,0,0}, // 0
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	1
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	2
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	3
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	4
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	5
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	6
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	7
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	8
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//	9
		}
	};
}

void DungeonMap::Draw(Texture& mapTex) {
    for (int y = 0; y < Height; y++) {
        for (int x = 0; x < Width; x++) {
            const int32 tile = map[y][x];
            int sprite = GetSprite(tile);
            Vec2 pos(x * TileSize, y * TileSize);
            mapTex(sprite * TileSize, 0, TileSize, TileSize).draw(pos);
        }
    }
}

Array<P2Body> DungeonMap::CreateColliders(P2World& world) {
    Array<P2Body> bodies;

    for (int y = 0; y < Height; y++) {
	    for (int x = 0; x < Width; x++) {
			const int32 tile = map[y][x];
			// wall
			if (GetType(tile) == TileType::wall) {
                Vec2 pos(x * TileSize + TileSize / 2, y * TileSize + TileSize / 2);
				bodies << world.createRect(P2Static, pos, SizeF{ TileSize, TileSize });
				obstaclePositions << Point(x, y);
			}
			// obstacle
			else if (GetType(tile) == TileType::obstacle) {
				Vec2 pos(x * TileSize + TileSize / 2, y * TileSize + TileSize / 2);
                bodies << world.createRect(P2Static, pos, SizeF{ TileSize, TileSize });
                obstaclePositions << Point(x, y);
			}
		}
    }

    return bodies;
}

Array<DungeonMap::Gimmick> DungeonMap::CreateGimmicks() {
    Array<Gimmick> gimmicks;

    for (int y = 0; y < Height; y++) {
        for (int x = 0; x < Width; x++) {
            const int32 tile = map[y][x];
            if (GetType(tile) == TileType::gimmick) {
                gimmicks << Gimmick(GetType(tile), Point(x, y), GetPairID(tile), TileSize);
            }
        }
    }

    return gimmicks;
}

void DungeonMap::LinkGimmicks(Array<Gimmick>& gimmicks) {
    for (auto& gimmick : gimmicks) {
        for (int i = 0; i < obstaclePositions.size(); ++i) {
            Point pos = obstaclePositions[i];
            if (GetPairID(map[pos.y][pos.x]) == gimmick.pairID) {
                gimmick.pairIndex = i;
                gimmick.pairTilePos = pos;
                break;
            }
        }
    }
}

void DungeonMap::ActivateGimmick(Gimmick& gimmick, Array<P2Body>& colliders) {
    if (gimmick.activated || gimmick.pairIndex < 0 || gimmick.pairIndex >= colliders.size())
        return;

    colliders[gimmick.pairIndex].release(); // disable obstacle collider

	int32& obstacleTile = map[gimmick.pairTilePos.y][gimmick.pairTilePos.x];
	SetSprite(obstacleTile, GetSprite(obstacleTile) + 1);
	SetType(obstacleTile, 0);
    SetStatus(obstacleTile, 0);

    Print << U"Gimmick activated at " << gimmick.tilePos << U" -> obstacle cleared at " << gimmick.pairTilePos;
    gimmick.activated = true;
}

void DungeonMap::UpdateGimmicks(Array<Gimmick>& gimmicks, Array<P2Body>& colliders, const P2Body& player) {
    const Circle playerCircle(player.getPos(), TileSize / 2);

    for (auto& gimmick : gimmicks) {
        if (!gimmick.activated && gimmick.collider.intersects(playerCircle) && KeyE.down()) {
            ActivateGimmick(gimmick, colliders);
        }
        // visualize gimmick
        //gimmick.collider.draw(gimmick.activated ? Palette::Gray : Palette::Cyan);
    }
}

void DungeonMap::DrawColliders(const Array<P2Body>& colliders) {
    for (const auto& body : colliders) {
        body.draw(ColorF{ 0.8 });
    }
}
