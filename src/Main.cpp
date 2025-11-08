# include "PlayerController.h"
# include "Camera.h"

void Main()
{
	Window::Resize(1280, 720);

	// 2D 物理演算のシミュレーションステップ（秒）
	constexpr double StepTime = (1.0 / 200.0);

	// 2D 物理演算のシミュレーション蓄積時間（秒）
	double accumulatedTime = 0.0;

	// 2D 物理演算のワールド
	P2World world;

	constexpr Vec2 m_firstPos{ 0, 0 };

	PlayerController m_player(&world, m_firstPos);
	Camera camera{&m_player, Vec2{0, 0}, Vec2{0, -300}, 0.5};
	// 地面
	Array<P2Body> grounds;
	grounds << world.createRect(P2Static, Vec2{ m_firstPos.x, m_firstPos.y + 300 }, SizeF{ 2000, 20 });
	grounds << world.createRect(P2Static, Vec2{ m_firstPos.x, m_firstPos.y + 100 }, SizeF{ 100, 20 });
	// grounds << world.createLine(P2Static, Vec2{ 0, 0 }, Line{ -500, -150, -300, -50 });
	// grounds << world.createLineString(P2Static, Vec2{ 0, 0 }, LineString{ Vec2{ 100, -50 }, Vec2{ 200, -50 }, Vec2{ 600, -150 } });

	while (System::Update())
	{
		ClearPrint();
		// Print << U"bodies.size(): " << bodies.size() << U"\n";

		double deltaTime = Scene::DeltaTime();
		for (accumulatedTime += deltaTime; StepTime <= accumulatedTime; accumulatedTime -= StepTime)
		{
			// 2D 物理演算のワールドを StepTime 秒進める
			world.update(StepTime);

			// 地面の下に 500 cm 以上落下した物体を削除する
			// bodies.remove_if([](const P2Body& body) { return (500 < body.getPos().y); });
		}
		m_player.Update(deltaTime);
		camera.Update();
		camera.Draw(grounds);
	}
}