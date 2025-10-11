#pragma once
#include <Siv3D.hpp>

class Enemy{
protected: 
P2Body body;
P2World* world;

public:
	Enemy(P2World* w) :world(w) {}
	~Enemy() {}

	virtual void update();
	virtual void fixedUpdate();

private:
	double accumulator = 0.0;
	const double h = 1.0/120.0;



	
};