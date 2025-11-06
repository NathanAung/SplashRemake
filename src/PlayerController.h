#pragma once

# include <Siv3D.hpp>

class PlayerController{
private:
	enum State{
			None,		// 例外用
			Solid,		// 固体
			Liquid,		// 液体
			Gas,		// 気体
		};
	const double m_moveSpeed = 300;		// 液体時：移動速度
	const double m_addForceOnSolid = 450;	// 固体時：横移動加速度
	const double m_floatSpeed = 200;	// 気体時：上昇速度
	const double m_maxHP = 100;			// 最大HP
	const Size m_collSize{ 100, 100 };	// 当たり判定のサイズ
	P2World* m_world;		// P2ワールド
	P2Body m_collider;		// 物理物体の当たり判定
	// 液体時のテクスチャ
	const Texture m_textureLiquid{ U"../App/Assets/Sprites/Player/pl_idle.png" };
	// 固体時のテクスチャ
	const Texture m_textureSolid{ U"../App/Assets/Sprites/Player/ps_move.png" };
	// 気体時のテクスチャ
	const Texture m_textureGas{ U"../App/Assets/Sprites/Player/pg_idle.png" };
	Texture m_sprite;				// 現在のスプライト
	State m_state;
	bool m_flipSprite = false;		// スプライトを反転するか

	void MoveHorizontal(Vec2* velocity);

	void ChangeLiquid();

	void ChangeSolid();

	void ChangeGas();

	void Float(Vec2 velocity);

	void Input();

public:
	PlayerController(P2World* world, Vec2 firstPos);

	~PlayerController();

	void Update();

	void Draw();

	P2Body* GetBody();
};