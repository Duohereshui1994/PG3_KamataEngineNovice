#include "Player.h"

Player::Player()
{
	pos_ = { 100.0f,320.0f };
	speed_ = 5.0f;
	hpMax_ = 100.0f;;
	hp_ = hpMax_;
	width = 64.0f;
	height = 64.0f;
	isAlive_ = true;
	CD_ = 0;
	texturePlayer_ = Novice::LoadTexture("./RS/player.png");
	bullets_.resize(10);
}

void Player::Init()
{
	pos_ = { 100.0f,320.0f };
	speed_ = 5.0f;
	hpMax_ = 100.0f;;
	hp_ = hpMax_;
	isAlive_ = true;
	CD_ = 0;
	for (auto& bullet : bullets_)
	{
		bullet.Initialize();
	}
}

void Player::Update()
{
	for (auto& bullet : bullets_)
	{
		bullet.Update();
	}
}

void Player::Draw()
{
	//描画
	for (auto& bullet : bullets_)
	{
		bullet.Draw();
	}
	Novice::DrawSprite(int(pos_.x), int(pos_.y), texturePlayer_, 1, 1, 0.0f, WHITE);
}

void Player::MoveRight()
{
	this->pos_.x += speed_;
}

void Player::MoveLeft()
{
	this->pos_.x -= speed_;
}

void Player::MoveUp()
{
	this->pos_.y -= speed_;
}

void Player::MoveDown()
{
	this->pos_.y += speed_;
}

void Player::Shoot()
{
	for (auto& bullet : bullets_)
	{
		if (bullet.GetIsShot() == false) {
			bullet.SetPos(pos_);
			bullet.SetIsShot(true);
			break;
		}
	}

}

