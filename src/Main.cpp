# include "PlayerController.h"
# include "Camera.h"
# include "Enemy.h"
# include "MeleeEnemy.h"
# include "DungeonMap.h"

void Main()
{
	Window::Resize(1280, 720);

	TextureAsset::Register(U"test",U"Assets/Sprites/Enemy/Melee/enemySprite.png");
	Texture mapTex(U"Assets/Tiles/basicTile.png");

	// 2D 物理演算のシミュレーションステップ（秒）
	constexpr double StepTime = (1.0 / 200.0);

	// 2D 物理演算のシミュレーション蓄積時間（秒）
	double accumulatedTime = 0.0;

	// 2D 物理演算のワールド
	P2World world;

	DungeonMap dungeon;

    Array<P2Body> colliders = dungeon.CreateColliders(world);
    Array<DungeonMap::Gimmick> gimmicks = dungeon.CreateGimmicks();
	dungeon.LinkGimmicks(gimmicks);

	Array<DungeonMap::Vent> vents = dungeon.CreateVents();

	Array<DungeonMap::Trap> traps = dungeon.CreateTraps();

	//Array<int> enemies = dungeon.CreateEnemies();	// placeholder


	constexpr Vec2 m_firstPos{ 0, 0 };

	PlayerController m_player(&world, m_firstPos);
	Camera camera{&m_player, Vec2{0, 0}, Vec2{0, -300}, 0.5};
	// 地面
	Array<P2Body> grounds;
	grounds << world.createRect(P2Static, Vec2{ m_firstPos.x, m_firstPos.y + 300 }, SizeF{ 2000, 20 });
	grounds << world.createRect(P2Static, Vec2{ m_firstPos.x, m_firstPos.y + 100 }, SizeF{ 100, 20 });

	Array<MeleeEnemy> enemies;
	enemies << MeleeEnemy(&world, U"test", Vec2{ 400, -600 }, 300, &m_player);
	enemies << MeleeEnemy(&world, U"test", Vec2{ -100, -600 }, 300, &m_player);

	// grounds << world.createLine(P2Static, Vec2{ 0, 0 }, Line{ -500, -150, -300, -50 });
	// grounds << world.createLineString(P2Static, Vec2{ 0, 0 }, LineString{ Vec2{ 100, -50 }, Vec2{ 200, -50 }, Vec2{ 600, -150 } });

	while (System::Update())
	{
		ClearPrint();
		// Print << U"bodies.size(): " << bodies.size() << U"\n";


		// Update Loop
		for (accumulatedTime += Scene::DeltaTime(); StepTime <= accumulatedTime; accumulatedTime -= StepTime)
		{
			// 2D 物理演算のワールドを StepTime 秒進める
			world.update(StepTime);

			
			//dungeon.UpdateGimmicks(gimmicks, colliders, player);
			//dungeon.UpdateVents(vents, player);
			//dungeon.UpdateTraps(traps, player);

			for (auto& enemy : enemies)
			{
				enemy.Update(StepTime);
			}

			
			// 地面の下に 500 cm 以上落下した物体を削除する
			// bodies.remove_if([](const P2Body& body) { return (500 < body.getPos().y); });
		}
		m_player.Update(StepTime);
		

		// Draw
		camera.Update();
		{
			const Transformer2D ct = camera.CreateTrans();

			dungeon.Draw(mapTex);
        	//dungeon.DrawColliders(colliders);
			
			for (const auto& field : grounds)
			{
				field.draw();
			}

			for (auto& enemy : enemies)
			{
				enemy.Draw();
			}

			m_player.Draw();
		}
		
		m_player.DrawUI();
	}
}