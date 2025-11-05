#pragma once
# include "Enemy.h"


class MeleeEnemy : public virtual Enemy
{
private:
	

public:
	using Enemy::Enemy;
	~MeleeEnemy() {}

	void Update(const double& deltaTime) override;
	void Draw() override;

	bool PlayerDetected() override;
	void Attack() override;
};


	
void MeleeEnemy::Update(const double& deltaTime) {
	Enemy::Update(deltaTime);

	
}

void MeleeEnemy::Draw(){
	//Enemy::Draw();

	const uint64 t = Time::GetMillisec();
	const int32 x = (t / 150 % 4);
	const int32 y = (t / 750 % 2);

	const int32 a = (Key9.pressed() ? 2 : 0); // select sprite stage
	
	sprite( 480 * x, 480 * (y + a), 480 , 480 ).resized(64).drawAt(body.getPos());
}

bool MeleeEnemy::PlayerDetected() {

	if(Key0.down()){
		return true;
	}

	return false;
}

void MeleeEnemy::Attack() {
	Print << U"ATTACK";
}
