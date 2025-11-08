#pragma once

# include <Siv3D.hpp>
# include "IceBullete.h"

enum State{
		None,		// 例外用
		Solid,		// 固体
		Liquid,		// 液体
		Gas,		// 気体
	};

class PlayerController{
private:
	const double m_moveSpeed = 300;				// 液体時：移動速度
	const double m_addForceOnSolid = 450;		// 固体時：横移動加速度
	const double m_floatSpeed = 200;			// 気体時：上昇速度
	const double m_maxHP = 100;					// 最大HP
	const double m_maxEP = 100;					// 最大EP
	const double m_epDecreaseSpeedPerSec = 20;	// EPの減少速度
	const double m_epIncreaseSpeedPerSec = 5;	// EPの上昇速度
	const Size m_collSize{ 100, 100 };	// 当たり判定のサイズ
	const Texture m_textureLiquid{ U"../App/Assets/Sprites/Player/pl_idle.png" };
	const int m_liquidCellSize = 480;

	// 固体時のテクスチャ
	const Texture m_textureSolid{ U"../App/Assets/Sprites/Player/ps_move.png" };
	const int m_solidCellSize = 480;

	// 気体時のテクスチャ
	const Texture m_textureGas{ U"../App/Assets/Sprites/Player/pg_idle.png" };
	const int m_gasCellSize = 384;
	Array<IceBullete*> m_iceBulletes;
	P2Body m_collider;		// 物理物体の当たり判定

	// 液体時のテクスチャ
	Texture m_sprite;				// 現在のスプライト
	State m_state;
	bool m_flipSprite = false;		// スプライトを反転するか
	double m_hp = m_maxHP;			// 現在のHP
	double m_ep = m_maxEP;			// 現在のEP

	// UI系
	Rect hpBar{20,20,300,30};
	Rect hpBarBg{20,20,300,30};
	Rect epBar{20,80,300,30};
	Rect epBarBg{20,80,300,30};

	void MoveHorizontal(Vec2 velocity);

	void ChangeLiquid();

	void ChangeSolid();

	void ChangeGas();

	void Shot();

	void Float(Vec2 velocity);

	void Input();

public:
	PlayerController(P2World* world, Vec2 firstPos);

	~PlayerController();

	void Update(double deltaTime);

	void Draw();

	void DrawUI();

	State GetState();

	P2Body* GetBody();

	Circle GetCollider();

	double HP();

	void OnDamage(double damage);

	double EP();

	Array<IceBullete*>* GetBullets();
};