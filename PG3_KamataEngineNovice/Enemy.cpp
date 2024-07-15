#include "Enemy.h"

Enemy::Enemy()
{
	pos_ = { 1300.0f,float(rand() % 656) };
	speed_ = 2.0f;
	width_ = 64.0f;
	height_ = 64.0f;
	isAlive_ = false;
	respawnTimer_ = 120 + rand() % 120;
	textureEnemy_ = Novice::LoadTexture("./RS/enemy.png");

}

void Enemy::Init()
{
	pos_ = { 1300.0f,float(rand() % 656) };
	isAlive_ = false;
	respawnTimer_ = 120 + rand() % 120;
}

void Enemy::Update()
{
	if (!isAlive_)
	{
		if (respawnTimer_ > 0)
		{
			respawnTimer_--;
		}
		else
		{
			pos_.x = 1400.0f;
			pos_.y = float(rand() % 656);
			respawnTimer_ = 120 + rand() % 120;
			isAlive_ = true;
		}
	}
	else
	{
		pos_.x -= speed_;

		if (pos_.x < -64.0f)
		{
			isAlive_ = false;
		}
	}
}

void Enemy::Draw()
{
	if (isAlive_)
	{
		Novice::DrawSprite((int)pos_.x, (int)pos_.y, textureEnemy_, 1, 1, 0.0f, WHITE);
	}
}

void Enemy::OnCollision(const Bullet* bullet)
{
	(void)bullet;
	isAlive_ = false;
}
void Enemy::OnCollision(const Player* player) {
	(void)player;
	isAlive_ = false;
}