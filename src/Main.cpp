# include <Siv3D.hpp>
#include "DungeonMap.h"

DungeonMap dungeonMap;

void Main()
{
	// 2D physics world
	P2World world;

	Window::Resize(640, 640);
	Texture mapTexture(U"map.png");

	Array<P2Body> mapColliders = dungeonMap.CreateMapCol(world);

	while (System::Update())
	{
		dungeonMap.DrawMap(mapTexture, 0);
		dungeonMap.DrawMap(mapTexture, 1);

		dungeonMap.DrawMapCol(mapColliders);
	}
}