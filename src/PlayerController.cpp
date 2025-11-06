#include "PlayerController.h"

void PlayerController::MoveHorizontal(Vec2 velocity)
{
	switch (m_state){
		case Liquid:
			if (KeyD.pressed()){
				m_collider.setVelocity( Vec2{ 1 * m_moveSpeed, velocity.y } );
			}
			if (KeyA.pressed()){
				m_collider.setVelocity( Vec2{ -1 * m_moveSpeed, velocity.y } );
			}
			if (!KeyD.pressed() && !KeyA.pressed()){
				m_collider.setVelocity( Vec2{ 0 , velocity.y } );
			}
			break;
		case Solid:
			if (KeyD.pressed()){
				m_collider.applyForce( Vec2{ 1 * m_addForceOnSolid, 0 } );
				velocity.x = Clamp(velocity.x, m_moveSpeed * -1, m_moveSpeed);
			}
			if (KeyA.pressed()){
				m_collider.applyForce( Vec2{ -1 * m_addForceOnSolid, 0 } );
				velocity.x = Clamp(velocity.x, m_moveSpeed * -1, m_moveSpeed);
			}
			if (!KeyD.pressed() && !KeyA.pressed()){
				if (velocity.x > 1){
					m_collider.applyForce( Vec2{ -1 * m_addForceOnSolid, 0 } );
				}
				else if (velocity.x < -1){
					m_collider.applyForce( Vec2{ m_addForceOnSolid, 0 } );
				}
				else{
					velocity.x = 0;
				}
			}
			m_collider.setVelocity(velocity);
			break;
		case Gas:
			if (KeyD.pressed()){
				m_collider.setVelocity( Vec2{ 1 * m_moveSpeed * 0.5, m_floatSpeed * -1 } );
			}
			if (KeyA.pressed()){
				m_collider.setVelocity( Vec2{ -1 * m_moveSpeed * 0.5, m_floatSpeed * -1 } );
			}
			if (!KeyD.pressed() && !KeyA.pressed()){
				m_collider.setVelocity( Vec2{ 0 , m_floatSpeed * -1 } );
			}
			break;
		default:
			break;

	}
}

void PlayerController::ChangeLiquid()
{
	if (m_state == Liquid) return;

	m_state = Liquid;
	m_sprite = m_textureLiquid;
}

void PlayerController::ChangeSolid()
{
	if (m_state == Solid) return;

	m_state = Solid;
	m_sprite = m_textureSolid;
}

void PlayerController::ChangeGas()
{
	if (m_state == Gas) return;

	m_state = Gas;
	m_sprite = m_textureGas;
}

void PlayerController::Float(Vec2 velocity)
{
	if (m_state != Gas) return;
	m_collider.setVelocity( Vec2{ velocity.x, m_floatSpeed } );
}

void PlayerController::Input()
{
	MoveHorizontal(m_collider.getVelocity());
	if (Key1.down())
		ChangeLiquid();
	else if (Key2.down())
		ChangeSolid();
	else if (Key3.down())
		ChangeGas();
}

PlayerController::PlayerController(P2World* world, Vec2 firstPos)
{
	m_state = Liquid;
	m_sprite = m_textureLiquid;
	m_collider = world->createRect(P2Dynamic, firstPos, m_collSize, P2Material{ 1.0f, 0, 0, 1.0f});
	m_collider.setFixedRotation(true);
}

PlayerController::~PlayerController()
{

}

void PlayerController::Update(double deltaTime)
{
	// m_position = m_collider.getPos();
	if (m_state != Liquid){
		m_ep = Max(m_ep - deltaTime * m_epDecreaseSpeedPerSec, 0.0);
		if (m_ep <= 0)
			ChangeLiquid();
	}
	else
		m_ep = Min(m_ep + deltaTime * m_epIncreaseSpeedPerSec, m_maxEP);
	Print << U"State " << m_state << U"\n";
	Print << U"EP： " << m_ep << U"\n";
	if (m_collider.getVelocity().x > 0)
		m_flipSprite = false;
	else if (m_collider.getVelocity().x < 0)
		m_flipSprite = true;
	// Float(m_collider.getVelocity());
	Input();
}

void PlayerController::Draw()
{
	int cellSize = 0;
	switch (m_state){
		case Liquid:
			cellSize = m_liquidCellSize;
			break;
		case Solid:
			cellSize = m_solidCellSize;
			break;
		case Gas:
			cellSize = m_gasCellSize;
			break;
		default:
			break;
	}
	m_sprite(0, 0, cellSize, cellSize).resized(200).mirrored(m_flipSprite).drawAt(m_collider.getPos());
}

State PlayerController::GetState()
{
    return m_state;
}

P2Body* PlayerController::GetBody()
{
    return &m_collider;
}

double PlayerController::HP()
{
    return m_hp;
}

void PlayerController::OnDamage(double damage)
{
	m_hp = Max(m_hp - damage, 0.0);
}

double PlayerController::EP()
{
    return m_ep;
}
