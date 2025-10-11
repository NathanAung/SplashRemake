#pragma once
#include "Enemy.h"
#include <Siv3D.hpp>

class MeleeEnemy : public Enemy {


public: 
	MeleeEnemy(P2World* w);
	~MeleeEnemy() {}

	void update() override;
	void fixedUpdate() override;
	void draw();

private:
	double accumulator = 0.0;
	const double h = 1.0/120.0;

};