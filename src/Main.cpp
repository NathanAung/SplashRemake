# include <Siv3D.hpp>
# include "Enemy.h"
# include "MeleeEnemy.h"

void Main()
{
	Window::Resize(1280, 720);

	TextureAsset::Register(U"test",U"Assets/Sprites/Enemy/Melee/enemySprite.png");

	// 2D physics simulation step time (seconds)
	double StepTime = (1.0 / 200.0);

	// 2D physics simulation accumulated time (seconds)
	double accumulatedTime = 0.0;

	// 2D physics world
	P2World world;

	const P2Body ground = world.createRect(P2Static, Vec2{ 200, 200 }, SizeF{ 1000, 10 });

	// Create 3 bodies (circles with radius 10cm)
	Array<MeleeEnemy> enemies;
	enemies << MeleeEnemy(&world, U"test", Vec2{ 200, -600 }, 50);

	// 2D camera (center coordinates (0, -300), zoom 1.0)
	Camera2D camera{ Vec2{ 200, 200 }, 1.5 };

	while (System::Update())
	{

		for (accumulatedTime += Scene::DeltaTime(); StepTime <= accumulatedTime; accumulatedTime -= StepTime)
		{
			world.update(StepTime);
			for (auto& enemy : enemies)
			{
				enemy.Update(StepTime);
			}
		}

		camera.update();
		{
			const auto t = camera.createTransformer();
			
			ground.draw(Palette::Gray);

			for (auto& enemy : enemies)
			{
				enemy.Draw();
			}
		
			
		}
		
		
	}
}