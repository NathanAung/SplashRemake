#pragma once

# include <Siv3D.hpp>
# include "PlayerController.h"

class Camera{
private:
	PlayerController* m_player;
	Camera2D m_camera;		// 2D カメラ
	Vec2 m_cameraOffset{ 0, -300 };	// カメラの座標補正値
	double m_cameraRatio = 0.5;

public:
	Camera(PlayerController* player, Vec2 firstPosition, Vec2 offset, double ratio);

	~Camera();

	void Update();

	void Draw(Array<P2Body> fields);

	Transformer2D CreateTrans(); // Create a Constant Tranfrom Reference
};