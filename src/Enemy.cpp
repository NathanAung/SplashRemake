# include "Enemy.h"
using namespace s3d;




void Enemy::update() {

	//fixed update
	accumulator += Scene::DeltaTime();
	while (accumulator >= h) {
		accumulator -= h;
		fixedUpdate();

	}
	
}


void Enemy::fixedUpdate() {

}