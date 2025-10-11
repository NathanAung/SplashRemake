# include <Siv3D.hpp>
#include "DungeonMap.h"

DungeonMap dungeonMap;

void Main()
{
	Window::Resize(640, 640);
	Texture mapTexture(U"map.png");
	while (System::Update())
	{
		dungeonMap.DrawMap(mapTexture, 0);
		dungeonMap.DrawMap(mapTexture, 1);
	}
}