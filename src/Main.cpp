# include <Siv3D.hpp>

# include "MeleeEnemy.h"


void Main()
{
	Window::Resize(1280, 720);

	constexpr double StepTime = (1.0 / 200.0);

	double accumulatedTime = 0.0;


	P2World* world = new P2World();

	Array<P2Body> grounds;
	grounds << world->createRect(P2Static, Vec2{ 0, 0 }, SizeF{ 1000, 10 });

	MeleeEnemy enemy1 = MeleeEnemy(world);



	Camera2D camera{ Vec2{ 0, -300 }, 1.0 };

	double motorSpeed = 0.0;

	while (System::Update())
	{
		for (accumulatedTime += Scene::DeltaTime(); StepTime <= accumulatedTime; accumulatedTime -= StepTime)
		{
			world->update(StepTime);

		}

		enemy1.update();

		camera.update();
		{
			const auto t = camera.createTransformer();

			for (const auto& ground : grounds)
			{
				ground.draw(Palette::Gray);
			}
			enemy1.draw();
		}

		camera.draw(Palette::Orange);

	}
}