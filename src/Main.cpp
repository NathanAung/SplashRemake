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
	Array<DungeonMap::Gimmick> mapGimmicks = dungeonMap.CreateMapGimmicks();


	// 2D physics simulation step time (seconds)
	constexpr double StepTime = (1.0 / 200.0);

	// 2D physics simulation accumulated time (seconds)
	double accumulatedTime = 0.0;
	// Create 3 bodies (circles with radius 10cm)
	Array<P2Body> bodies;
	bodies << world.createCircle(P2Dynamic, Vec2{ 200, -900 }, 10);



	while (System::Update())
	{
		// ClearPrint();
		// for (const auto& body : bodies)
		// {
		// 	Print << U"ID: {}, {:.1f} cm"_fmt(body.id(), body.getPos());
		// }

		for (accumulatedTime += Scene::DeltaTime(); StepTime <= accumulatedTime; accumulatedTime -= StepTime)
		{
			// Advance the 2D physics world by StepTime seconds
			world.update(StepTime);

			// Remove bodies that have fallen more than 500 cm below ground
			bodies.remove_if([](const P2Body& body) { return (500 < body.getPos().y); });
		}

		

		dungeonMap.DrawMap(mapTexture, 0);
		dungeonMap.DrawMap(mapTexture, 1);

		dungeonMap.DrawMapCol(mapColliders);

		for (const auto& body : bodies)
		{
			body.draw(HSV{ body.id() * 10.0 });
		}

		dungeonMap.UpdateMapGimmicks(mapGimmicks, mapColliders, bodies[0]);
	}
}