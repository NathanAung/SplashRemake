#pragma once
# include "Enemy.h"


class MeleeEnemy : public virtual Enemy
{
private:
	Rect playerTrigger;

public:
	//using Enemy::Enemy;
	MeleeEnemy(P2World* world, String spriteName, Vec2 sP, double pSize);
	~MeleeEnemy() {}

	void Update(const double& deltaTime) override;
	void Draw() override;

	bool PlayerDetected() override;
	void Attack() override;
};

MeleeEnemy::MeleeEnemy(P2World* world, String spriteName, Vec2 sP, double pSize)
	: Enemy(world, spriteName, sP, pSize) {
	
	playerTrigger = Rect(startPos.x,startPos.y,64.0,64.0);
}
	
void MeleeEnemy::Update(const double& deltaTime) {
	Enemy::Update(deltaTime);

	playerTrigger.setPos(body.getPos().x,body.getPos().y - 32.0);

	playerTrigger.setSize(64.0 * fwdDirection, 64.0);
}

void MeleeEnemy::Draw(){
	//Enemy::Draw();
	//playerTrigger.draw(Palette::Greenyellow);

	const uint64 t = Time::GetMillisec();
	const int32 x = (t / 150 % 4);
	const int32 y = (t / 750 % 2);

	const int32 a = (Key9.pressed() ? 2 : 0); // select sprite stage
	
	sprite( 480 * x, 480 * (y + a), 480 , 480 ).mirrored(fwdDirection < 0).resized(64).drawAt(body.getPos());
}

bool MeleeEnemy::PlayerDetected() {

	if(Key0.pressed()){ //intersect player as : playerTrigger.intersects(player.collider)
		stopMove = true;
		return true;
	}

	stopMove = false;
	return false;
}

void MeleeEnemy::Attack() {
	//Print << U"ATTACK";
}
