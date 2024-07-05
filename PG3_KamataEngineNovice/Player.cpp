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
	CD = 0;
}

void Player::Init()
{
	pos_ = { 100.0f,320.0f };
	speed_ = 5.0f;
	hpMax_ = 100.0f;;
	hp_ = hpMax_;
	isAlive_ = true;
	CD = 0;
	for (int i = 0; i < 10; i++)
	{
		bullet[i].Initalize();
	}
}

void Player::Update()
{
	for (int i = 0; i < 10; i++)
	{
		bullet[i].Update();
	}
}

void Player::Draw()
{
	//描画
	for (int i = 0; i < 10; i++)
	{
		bullet[i].Draw();
	}
	Novice::DrawBox(int(pos_.x), int(pos_.y), 25, 25, 0.0f, WHITE, kFillModeSolid);
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
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i].GetIsShot() == false) {
			bullet[i].SetPos(pos_);
			bullet[i].SetIsShot(true);
			break;
		}
	}

}

