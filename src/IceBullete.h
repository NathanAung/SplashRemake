#pragma once

# include <Siv3D.hpp>

class IceBullete{
public:
	IceBullete(Vec2 firstPos, Vec2 direction);

	void Update(double deltaTime);

	void Draw();

	Rect* GetCollider();

	bool IsActive();

	void Init(Vec2 firstPos, Vec2 direction);

	void OnHit();

private:
	// 氷攻撃のテクスチャ
	const Texture m_textureIceAttack{ U"../App/Assets/Sprites/Player/Icicle/icicle.png" };
	const int m_iceAttackCellSize = 400;
	const double m_moveSpeed = 600.0;
	const double m_lifeTime = 3;
	double m_currentTime = 0;
	bool m_isActive;
	TextureRegion m_sprite;
	Vec2 m_moveDirection;
	Vec2 m_position;
	Rect m_collider{ 80, 25 };
};