#include "Bullet.h"

Bullet::Bullet()
{
	pos_.x = -100.0f;
	pos_.y = -100.0f;
	isShot_ = false;
	width_ = 32.0f;
	height_ = 32.0f;
	speed_ = 30.0f;
}

Bullet::~Bullet()
{

}

void Bullet::Initialize()
{
	pos_.x = -100.0f;
	pos_.y = -100.0f;
	isShot_ = false;
}

void Bullet::Update()
{
	if (isShot_) {
		pos_.x += speed_;
		if (pos_.x > 1280) {
			Initialize();
		}
	}
}

void Bullet::Draw()
{
	if (isShot_)
	{
		//int Texture_Bullet = Novice::LoadTexture("./RS/bulle_player.png");
		//Novice::DrawSprite((int)pos_.x, (int)pos_.y + 16, Texture_Bullet, 1, 1, 0.0f, WHITE);
		Novice::DrawBox((int)pos_.x, (int)pos_.y + 16, 32, 32, 0.0f, BLUE, kFillModeSolid);
	}
}
