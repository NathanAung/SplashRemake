#pragma once
#include <Siv3D.hpp> // Siv3D v0.6.16

class DungeonMap {
public:
	// button
	struct Gimmick {
        int type = 0;
        Point tilePos;
        int pairID = 0;
        bool activated = false;
        int pairIndex = -1;     // index in collider array
        Point pairTilePos;
        Rect collider;

        Gimmick(int t, Point pos, int id, int tileSize)
            : type(t), tilePos(pos), pairID(id), collider(pos.x * tileSize, pos.y * tileSize, tileSize) {}
	};

	struct Vent {
		Point tilePos;
		Rect collider;

		Vent(Point pos, int tileSize)
			: tilePos(pos), collider(pos.x * tileSize, pos.y * tileSize, tileSize) {}
	};

	struct Trap {
		int type = 0;
		Point tilePos;
		Rect collider;

		Trap(int t, Point pos, int tileSize)
			: type(t), tilePos(pos), collider(pos.x * tileSize, pos.y * tileSize, tileSize) {}
	};

	enum TileType {
		normal,
		wall,
		obstacle,
		gimmick,
		vent,
		trap,
		enemy
	};

	enum TileStatus {
		none,
		activated
	};

    DungeonMap();

	// map general
	void Draw(Texture& mapTex);
	Array<P2Body> CreateColliders(P2World& world);
	void DrawColliders(const Array<P2Body>& colliders);	// debug
	
	// gimmicks
	Array<Gimmick> CreateGimmicks();
    void LinkGimmicks(Array<Gimmick>& gimmicks);	// for linking buttons to corresponding obstacles
    void UpdateGimmicks(Array<Gimmick>& gimmicks, Array<P2Body>& colliders, const P2Body& player);

	// vents
	Array<Vent> CreateVents();
	void UpdateVents(const Array<Vent>& vents, P2Body& player);

	// traps
	Array<Trap> CreateTraps();
	void UpdateTraps(const Array<Trap>& traps, const P2Body& player);

	// enemies
	Array<int> CreateEnemies();	// placeholder

private:
    static constexpr int TileSize = 200;
	static constexpr int SpriteTileSize = 400;
    static constexpr int Width = 20;
    static constexpr int Height = 20;

    Grid<int32> map;
	Array<Point> obstaclePositions;	// positions of objects you can collide with
	HashTable<Point, int32> tileToColliderIndex;	// for mapping collider position and index in collider array

	// bit accessors
	// 00 - 07 bits: sprite index on texture
	static int GetSprite(int32 value) { return (value & 0xFF); }
	// 08 - 15 bits: type: 0 - normal, 1 - wall, 2 - obstacle, 3 - gimmick, 4 - vent, 5 - trap, 6 - enemy
	static int GetType(int32 value) { return (value >> 8) & 0xFF; }
	// 16 - 23 bits: status: 0 - none, 1 - activated, 
	// for enemies, enemy types: 0 - melee, 2 - magic, 3 - flying
	static int GetStatus(int32 value) { return (value >> 16) & 0xFF; }
	// 24 - 31 bits: pair index for linking gimmicks and obstacles  
    static int GetPairID(int32 value) { return (value >> 24) & 0xFF; }

	// corresponding setters
	static void SetSprite(int32& value, int idx) { value = (value & ~0xFF) | (idx & 0xFF); }
    static void SetType(int32& value, int idx) { value = (value & ~(0xFF << 8)) | ((idx & 0xFF) << 8); }
    static void SetStatus(int32& value, int idx) { value = (value & ~(0xFF << 16)) | ((idx & 0xFF) << 16); }
    static void SetPairID(int32& value, int idx) { value = (value & ~(0xFF << 24)) | ((idx & 0xFF) << 24); }

    void ActivateGimmick(Gimmick& gimmick, Array<P2Body>& colliders);
};
