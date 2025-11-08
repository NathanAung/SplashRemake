#pragma once
# include "Enemy.h"


class MeleeEnemy : public virtual Enemy
{
private:
	Rect playerTrigger;

	bool attackCooldown = false;

public:
	//using Enemy::Enemy;
	MeleeEnemy(P2World* world, String spriteName, Vec2 sP, double pSize, PlayerController* pl);
	~MeleeEnemy() {}

	void Update(const double& deltaTime) override;
	void Draw() override;

	bool PlayerDetected() override;
	void Attack() override;
};

MeleeEnemy::MeleeEnemy(P2World* world, String spriteName, Vec2 sP, double pSize, PlayerController* pl)
	: Enemy(world, spriteName, sP, pSize, pl) {
	
	playerTrigger = Rect(startPos.x,startPos.y,100.0,150.0);
}
	
void MeleeEnemy::Update(const double& deltaTime) {
	Enemy::Update(deltaTime);

	playerTrigger.setPos(body.getPos().x + (fwdDirection > 0 ? 0 : -100),body.getPos().y - 75.0);
}

void MeleeEnemy::Draw(){
	//Enemy::Draw();
	//playerTrigger.draw(Palette::Greenyellow);

	const uint64 t = Time::GetMillisec();
	const int32 x = (t / 150 % 4);
	const int32 y = (t / 750 % (stopMove ? 1 : 2));

	const int32 a = (stopMove ? 4 : 0); // select sprite stage

	
	sprite( 480 * x, 480 * (y + a), 480 , 480 ).mirrored(fwdDirection < 0).resized(200).drawAt(body.getPos());
}

bool MeleeEnemy::PlayerDetected() {

	if(playerTrigger.intersects(player->GetCollider())){ //intersect player as : playerTrigger.intersects(player.collider)
		stopMove = true;
		return true;
	}

	stopMove = false;
	return false;
}

void MeleeEnemy::Attack() {
	const uint64 t = Time::GetMillisec();

	if( stopMove && (t / 150 % 4) == 2 && !attackCooldown){
		player->OnDamage(10);
		attackCooldown = true;
	}

	if((t / 150 % 4) != 2)
		attackCooldown = false;
}
