#include "DungeonMap.h"

/*
	MAP TILE DATA:
	00 - 07 bits: sprite index on texture
	08 - 15 bits: type: 0 - normal, 1 - wall, 2 - obstacle, 3 - gimmick, 4 - vent, 5 - trap, 6 - enemy
	16 - 23 bits: status: 0 - none, 1 - activated| for enemies, enemy types: 0 - melee, 2 - magic, 3 - flying
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
	{0x00000105,0x00000105,0x0000010D,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x00000108,0x0000010C,0x00000105},
	{0x00000105,0x0000010D,0x00000109,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000107,0x0000010C},
	{0x00000105,0x00000106,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000104},
	{0x0000010D,0x00000109,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000104},
	{0x00000106,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000104},
	{0x00000106,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000101,0x00000103,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000104},
	{0x00000106,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000104,0x00000106,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000104},
	{0x00000106,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000104,0x00000106,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000104},
	{0x00000106,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000101,0x00000103,0x00000000,0x00000000,0x00000000,0x00000000,0x00000101,0x00000102,0x00000102,0x00000102,0x00000102,0x00000102,0x00000102,0x00000102,0x0000010A,0x0000010B,0x00000102,0x00000102,0x00000102,0x00000102,0x00000102,0x00000102,0x00000102,0x0000010A},
	{0x00000106,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000101,0x00000103,0x00000109,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000104,0x00000105,0x00000105,0x00000105,0x00000105,0x00000105,0x00000105,0x0000010D,0x00000108,0x00000108,0x00000108,0x00000108,0x0000010C,0x00000105,0x00000105,0x00000105,0x00000105,0x00000105}
		}
	};
}


// draw the map on the screen
void DungeonMap::Draw(Texture& mapTex) {
    for (int y = 0; y < Height; y++) {
        for (int x = 0; x < Width; x++) {
            const int32 tile = map[y][x];
            int sprite = GetSprite(tile);
            Vec2 pos(x * TileSize, y * TileSize);
            mapTex(sprite * SpriteTileSize, 0, SpriteTileSize, SpriteTileSize).scaled(0.5).draw(pos);
        }
    }
}


// create and group colliders
Array<P2Body> DungeonMap::CreateColliders(P2World& world) {
    Array<P2Body> bodies;
    obstaclePositions.clear();
    tileToColliderIndex.clear();

	for (int y = 0; y < Height; ++y) {
		// for tracking a run on a wall of tiles
		int runStart = -1;
        int runLength = 0;

		for (int x = 0; x <= Width; ++x) {
			// check if tile is a wall
			bool isWall = (x < Width && GetType(map[y][x]) == TileType::wall);

			if (isWall) {
				// set index if so, or increase length if start already exists
				if (runStart == -1) runStart = x;
                ++runLength;
			}
			// place walls when this tile is not wall, but run length is increased
			else if (runLength > 0) {
                const double startX = runStart * TileSize;
                const double width = runLength * TileSize;
                const double centerX = startX + width / 2;
                const double centerY = y * TileSize + TileSize / 2;

                int colliderIndex = bodies.size();	// index in the collider array
                bodies << world.createRect(P2Static, Vec2(centerX, centerY), SizeF{ width, TileSize });

                // Map each tile in this wall run to the same collider index
                for (int i = 0; i < runLength; ++i) {
                    Point pos(runStart + i, y);
                    obstaclePositions << pos;
                    tileToColliderIndex[pos] = colliderIndex;
                }

                runStart = -1;
                runLength = 0;
            }

            // Handle individual obstacles
            if (x < Width && GetType(map[y][x]) == TileType::obstacle) {
                Vec2 pos((x + 0.5) * TileSize, (y + 0.5) * TileSize);
                int colliderIndex = bodies.size();
                bodies << world.createRect(P2Static, pos, SizeF{ TileSize, TileSize });
                Point tilePos(x, y);
                obstaclePositions << tilePos;
                tileToColliderIndex[tilePos] = colliderIndex;
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

Array<DungeonMap::Vent> DungeonMap::CreateVents() {
	Array<Vent> vents;

	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			const int32 tile = map[y][x];
			if (GetType(tile) == TileType::vent) {
				vents << Vent(Point(x, y), TileSize);
				Print << U"Vent created at (" << x << U"," << y << U")";
			}
		}
	}

	return vents;
}


Array<DungeonMap::Trap> DungeonMap::CreateTraps() {
	Array<Trap> traps;

	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			const int32 tile = map[y][x];
			if (GetType(tile) == TileType::trap) {
				traps << Trap(GetType(tile), Point(x, y), TileSize);
				Print << U"Trap created at (" << x << U"," << y << U")";
			}
		}
	}

	return traps;
}


// Placeholder for enemy creation logic
Array<int> DungeonMap::CreateEnemies() {
	Array<int> enemies; // Replace int with actual Enemy class when implemented

	for(int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			const int32 tile = map[y][x];
			if (GetType(tile) == TileType::enemy) {
				// Create enemy based on type and position
				if(GetStatus(tile) == 0) {
					// Melee enemy
					Print << U"Creating Melee enemy at (" << x << U"," << y << U")";
				}
				else if (GetStatus(tile) == 1) {
					// Magic enemy
					Print << U"Creating Magic enemy at (" << x << U"," << y << U")";
				}
				else if (GetStatus(tile) == 2) {
					// Flying enemy
					Print << U"Creating Flying enemy at (" << x << U"," << y << U")";
				}
				enemies << tile; // Placeholder: store tile info, replace with actual enemy object
			}
		}
	}
	return enemies;
}


// link gimmicks to corresponding obstacles
void DungeonMap::LinkGimmicks(Array<Gimmick>& gimmicks) {
    for (auto& gimmick : gimmicks) {
        for (const auto& [pos, colliderIndex] : tileToColliderIndex) {
            if (GetPairID(map[pos.y][pos.x]) == gimmick.pairID) {
                gimmick.pairIndex = colliderIndex;
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

void DungeonMap::UpdateVents(const Array<Vent>& vents, P2Body& player) {
	const Circle playerCircle(player.getPos(), TileSize / 2);

	for (const auto& vent : vents) {
		if (vent.collider.intersects(playerCircle)) {
			Print << U"Player near vent at " << vent.tilePos;
			// Handle vent effect here (e.g., play sound, trigger animation)

		}
		// visualize vent
		//vent.collider.draw(Palette::Blue);
	}
}


void DungeonMap::UpdateTraps(const Array<Trap>& traps, const P2Body& player) {
	const Circle playerCircle(player.getPos(), TileSize / 2);

	for (const auto& trap : traps) {
		if (trap.collider.intersects(playerCircle)) {
			Print << U"Player triggered trap at " << trap.tilePos;
			// Handle trap effect here (e.g., reduce health)
		}
		// visualize trap
		//trap.collider.draw(Palette::Red);
	}
}


void DungeonMap::DrawColliders(const Array<P2Body>& colliders) {
    for (const auto& body : colliders) {
        body.draw(HSV{ body.id() * 10.0 });
    }
}
