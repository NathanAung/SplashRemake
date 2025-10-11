#include "MeleeEnemy.h"
using namespace s3d;


MeleeEnemy::MeleeEnemy(P2World* w) : Enemy(w)
{
	body = world->createCircle(P2Dynamic, Vec2{ -100, -300 }, 50);
}


void MeleeEnemy::update() {


	//fixed update
	accumulator += Scene::DeltaTime();
	while (accumulator >= h) {
		accumulator -= h;
		fixedUpdate();

	}
}

void MeleeEnemy::fixedUpdate() {

}

void MeleeEnemy::draw() {
	body.draw(HSV{ body.id() * 10.0 });
}