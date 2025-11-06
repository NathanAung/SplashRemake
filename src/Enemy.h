#pragma once
# include <Siv3D.hpp>

class Enemy
{
protected:
	P2Body body;

	Vec2 startPos;
	double pathSize;
	double fwdDirection = 1.0;

	Texture sprite;

public:
	Enemy(P2World* world, String spriteName, Vec2 sP, double pSize);
	~Enemy();

	virtual void Update(const double& deltaTime);
	virtual void Draw();

	virtual bool PlayerDetected();
	virtual void Attack();
};

Enemy::Enemy(P2World* world, String spriteName, Vec2 sP, double pSize)
	: startPos{sP}, pathSize{pSize}
{
	body = world->createCircle(P2Dynamic, startPos, 10);
	sprite = TextureAsset(spriteName);
}

Enemy::~Enemy()
{

}

void Enemy::Update(const double& deltaTime){

	if(body.getPos().x > startPos.x + pathSize)
		fwdDirection = -1.0;

	if(body.getPos().x < startPos.x - pathSize)
		fwdDirection = 1.0;
		
	if(Math::Abs(body.getVelocity().x) > 10.0)
		body.setVelocity({50.0 * Math::Sign(fwdDirection) ,body.getVelocity().y});

	body.applyForce(Vec2{ 100.0 * fwdDirection , 0.0 } * deltaTime);

	if(PlayerDetected()){
		Attack();
	}
}

void Enemy::Draw(){
	body.draw(HSV{ body.id() * 10.0 });
	
}

bool Enemy::PlayerDetected() { return false; }

void Enemy::Attack() {}
