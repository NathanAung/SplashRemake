# include <Siv3D.hpp>

void Main()
{
	Window::Resize(1280, 720);

	// 2D 物理演算のシミュレーションステップ（秒）
	constexpr double StepTime = (1.0 / 200.0);

	// 2D 物理演算のシミュレーション蓄積時間（秒）
	double accumulatedTime = 0.0;

	// 2D 物理演算のワールド
	P2World world;

	// 地面
	Array<P2Body> grounds;
	grounds << world.createRect(P2Static, Vec2{ 0, -200 }, SizeF{ 600, 20 });
	grounds << world.createLine(P2Static, Vec2{ 0, 0 }, Line{ -500, -150, -300, -50 });
	grounds << world.createLineString(P2Static, Vec2{ 0, 0 }, LineString{ Vec2{ 100, -50 }, Vec2{ 200, -50 }, Vec2{ 600, -150 } });

	Array<P2Body> bodies;

	// 2D カメラ（中心座標 (0, -300), 拡大率 1.0）
	Camera2D camera{ Vec2{ 0, -300 }, 1.0 };

	while (System::Update())
	{
		ClearPrint();
		Print << U"bodies.size(): " << bodies.size() << U"\n";

		for (accumulatedTime += Scene::DeltaTime(); StepTime <= accumulatedTime; accumulatedTime -= StepTime)
		{
			// 2D 物理演算のワールドを StepTime 秒進める
			world.update(StepTime);

			// 地面の下に 500 cm 以上落下した物体を削除する
			bodies.remove_if([](const P2Body& body) { return (500 < body.getPos().y); });
		}

		// 2D カメラを更新する
		camera.update();
		{
			// 2D カメラから Transformer2D を作成する
			const auto t = camera.createTransformer();

			// すべての地面を描画する
			for (const auto& ground : grounds)
			{
				ground.draw(Palette::Gray);
			}

			// すべてのボディを描画する
			for (const auto& body : bodies)
			{
				body.draw(HSV{ body.id() * 10.0 });
			}
		}

		// 2D カメラの操作を描画する
		camera.draw(Palette::Orange);

		if (SimpleGUI::Button(U"Circle", Vec2{ 40, 80 }, 120))
		{
			bodies << world.createCircle(P2Dynamic, Vec2{ Random(-400, 400), -600 }, 20);
		}

		if (SimpleGUI::Button(U"Rect", Vec2{ 40, 120 }, 120))
		{
			bodies << world.createRect(P2Dynamic, Vec2{ Random(-400, 400), -600}, Size{20, 60});
		}

		if (SimpleGUI::Button(U"Triangle", Vec2{ 40, 160 }, 120))
		{
			bodies << world.createTriangle(P2Dynamic, Vec2{ Random(-400, 400), -600 }, Triangle{ 40 });
		}

		if (SimpleGUI::Button(U"Quad", Vec2{ 40, 200 }, 120))
		{
			bodies << world.createQuad(P2Dynamic, Vec2{ Random(-400, 400), -600 }, RectF{ Arg::center(0, 0), 40 }.skewedX(45_deg) );
		}

		if (SimpleGUI::Button(U"Polygon", Vec2{ 40, 240 }, 120))
		{
			const Polygon polygon = Shape2D::NStar(5, 30, 20);
			bodies << world.createPolygon(P2Dynamic, Vec2{ Random(-400, 400), -600 }, polygon);
		}
	}
}