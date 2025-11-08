#include "IceBullete.h"


IceBullete::IceBullete(Vec2 firstPos, Vec2 direction)
{
	m_moveDirection = direction;
	m_sprite = m_textureIceAttack(0, 0, m_iceAttackCellSize, m_iceAttackCellSize)
						.resized(100)
						.mirrored(m_moveDirection.x < 0);
	m_position = firstPos;
	m_collider.setCenter(m_position.x, m_position.y);
	m_isActive = true;
}

void IceBullete::Update(double deltaTime)
{
	if (!m_isActive) return;
	m_currentTime += deltaTime;
	if (m_currentTime >= m_lifeTime)
		m_isActive = false;
	m_position += m_moveDirection * m_moveSpeed * deltaTime;
	m_collider.setCenter(m_position.x, m_position.y);
}

void IceBullete::Draw()
{
	if (!m_isActive) return;
	m_collider.draw(Palette::Aliceblue);
	m_sprite.drawAt(m_position);
}

Rect* IceBullete::GetCollider()
{
    return &m_collider;
}

bool IceBullete::IsActive()
{
    return m_isActive;
}

void IceBullete::Init(Vec2 firstPos, Vec2 direction)
{
	m_moveDirection = direction;
	m_sprite = m_textureIceAttack(0, 0, m_iceAttackCellSize, m_iceAttackCellSize)
						.resized(100)
						.mirrored(m_moveDirection.x < 0);
	m_position = firstPos;
	m_isActive = true;
}

void IceBullete::OnHit()
{
	m_isActive = false;
}
