# include <Siv3D.hpp>

class Player{
	private:
		enum State{
			None,		// 例外用
			Solid,		// 固体
			Liquid,		// 液体
			Gas,		// 気体
		};
		const float m_moveForce = 150;		// 移動速度
		const float m_jumpForce = 1500;		// ジャンプ時に加わる力
		const float m_maxHP = 100;			// 最大HP
		const Vec2 m_cameraOffset{ 0, -300 };	// カメラの座標補正値
		const float m_cameraRatio = 0.5;
		P2World* m_world;		// P2ワールド
		P2Body m_collider;		// 物理物体の当たり判定
		Texture m_sprite;		// プレイヤーの見た目のテクスチャ
		Camera2D m_camera;		// 2D カメラ
		State m_state;

		void MoveHorizontal(Vec2 velocity){
			if (KeyD.pressed()){
				m_collider.setVelocity( Vec2{ 1 * m_moveForce, velocity.y } );
			}
			if (KeyA.pressed()){
				m_collider.setVelocity( Vec2{ -1 * m_moveForce, velocity.y } );
			}
			if (KeyD.up() || KeyA.up()){
				m_collider.setVelocity( Vec2{ 0 * m_moveForce, velocity.y } );
			}
		}

		void Jump(){
			if (KeySpace.down()){
				m_collider.applyLinearImpulse( Vec2{ 0, m_jumpForce });
			}
		}

	public:
		/// @brief 
		/// @param world P2World
		/// @param firstPos 
		Player(P2World* world, Vec2 firstPos){
			m_state = Solid;
			m_world = world;
			const Image image{ U"../App/Assets/Sprites/Player/slime.png" };
			m_sprite = Texture(image.scaled(0.1));
			m_collider = m_world->createRect(P2Dynamic, firstPos, image.scaled(0.06).size(), P2Material{ 1.0f, 0, 0, 1.0f});
			m_collider.setFixedRotation(true);
			m_camera = { firstPos + m_cameraOffset, m_cameraRatio };
		}

		void Update(){
			// m_position = m_collider.getPos();
			Print << U"State " << m_state << U"\n";
			Vec2 velocity = m_collider.getVelocity();
			MoveHorizontal(velocity);
			// Jump();
			m_camera.setCenter(m_collider.getPos() + m_cameraOffset);
		}

		void Draw(Array<P2Body> bodies){
			// m_camera.update();
			{
				const auto t = m_camera.createTransformer();
				m_sprite.drawAt(m_collider.getPos());
				// すべての地面を描画する
				for (const auto& body : bodies)
				{
					body.draw(Palette::Gray);
				}
			}
			m_camera.draw(Palette::Orange);
		}
};

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

	Player m_player(&world, m_firstPos);
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

		for (accumulatedTime += Scene::DeltaTime(); StepTime <= accumulatedTime; accumulatedTime -= StepTime)
		{
			// 2D 物理演算のワールドを StepTime 秒進める
			world.update(StepTime);

			// 地面の下に 500 cm 以上落下した物体を削除する
			// bodies.remove_if([](const P2Body& body) { return (500 < body.getPos().y); });
		}
		m_player.Update();
		m_player.Draw(grounds);
	}
}