#include "PlayerController.h"

void PlayerController::MoveHorizontal(Vec2* velocity)
{
	switch (m_state){
		case Liquid:
			if (KeyD.pressed()){
				m_collider.setVelocity( Vec2{ 1 * m_moveSpeed, velocity->y } );
			}
			if (KeyA.pressed()){
				m_collider.setVelocity( Vec2{ -1 * m_moveSpeed, velocity->y } );
			}
			if (KeyD.up() || KeyA.up()){
				m_collider.setVelocity( Vec2{ 0 , velocity->y } );
			}
			break;
		case Solid:
			if (KeyD.pressed()){
				m_collider.applyForce( Vec2{ 1 * m_addForceOnSolid, 0 } );
				velocity->x = Clamp(velocity->x, m_moveSpeed * -1, m_moveSpeed);
				m_collider.setVelocity(*velocity);
			}
			if (KeyA.pressed()){
				m_collider.applyForce( Vec2{ -1 * m_addForceOnSolid, 0 } );
				velocity->x = Clamp(velocity->x, m_moveSpeed * -1, m_moveSpeed);
				m_collider.setVelocity(*velocity);
			}
			break;
		case Gas:
			if (KeyD.pressed()){
				m_collider.setVelocity( Vec2{ 1 * m_moveSpeed * 0.5, velocity->y } );
			}
			if (KeyA.pressed()){
				m_collider.setVelocity( Vec2{ -1 * m_moveSpeed * 0.5, velocity->y } );
			}
			if (KeyD.up() || KeyA.up()){
				m_collider.setVelocity( Vec2{ 0 , velocity->y } );
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
	MoveHorizontal(&m_collider.getVelocity());
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
	m_world = world;
	m_sprite = m_textureLiquid;
	m_collider = m_world->createRect(P2Dynamic, firstPos, m_collSize, P2Material{ 1.0f, 0, 0, 1.0f});
	m_collider.setFixedRotation(true);
}

PlayerController::~PlayerController()
{
	delete m_world;
}

void PlayerController::Update()
{
	// m_position = m_collider.getPos();
	Print << U"State " << m_state << U"\n";
	if (m_collider.getVelocity().x > 0)
		m_flipSprite = false;
	else if (m_collider.getVelocity().x < 0)
		m_flipSprite = true;
	Input();
	Float(m_collider.getVelocity());
}

void PlayerController::Draw()
{
	m_sprite(0, 0, 960, 960).resized(200).mirrored(m_flipSprite).drawAt(m_collider.getPos());
}

P2Body* PlayerController::GetBody()
{
    return &m_collider;
}
