#include "Camera.h"

Camera::Camera(PlayerController* player, Vec2 firstPosition, Vec2 offset, double ratio)
{
	m_player = player;
	m_cameraOffset = offset;
	m_cameraRatio = ratio;
	m_camera = { firstPosition + m_cameraOffset, m_cameraRatio };
}

Camera::~Camera()
{
	delete m_player;
}

void Camera::Update()
{
	m_camera.setCenter(m_player->GetBody()->getPos() + m_cameraOffset);
}

void Camera::Draw(Array<P2Body> fields)
{
	const auto t = m_camera.createTransformer();
	{
		m_player->Draw();
		for (const auto& field : fields)
		{
			field.draw();
		}
	}
	m_camera.draw();
}

Transformer2D Camera::CreateTrans(){
	return m_camera.createTransformer();
}
