#include "Player.h"

Player::Player()
{
	pos_.x = 100.0f;
	pos_.y = 100.0f;
	speed_ = 5.0f;
}

void Player::Init()
{
	pos_.x = 100.0f;
	pos_.y = 100.0f;
	speed_ = 5.0f;
}

void Player::Update()
{
}

void Player::Draw()
{
	//描画
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

