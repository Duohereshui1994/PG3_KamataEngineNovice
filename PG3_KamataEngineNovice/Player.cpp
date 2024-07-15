#include "Player.h"

Player::Player()
{
	pos_ = { 100.0f,320.0f };
	speed_ = 5.0f;
	hpMax_ = 100.0f;;
	hp_ = hpMax_;
	width_ = 64.0f;
	height_ = 64.0f;
	isAlive_ = true;
	CD_ = 0;
	texturePlayer_ = Novice::LoadTexture("./RS/player.png");
	bullets_.resize(10);
}

Player::~Player()
{


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
	//本体描画
	for (auto& bullet : bullets_)
	{
		bullet.Draw();
	}
	Novice::DrawSprite(int(pos_.x), int(pos_.y), texturePlayer_, 1, 1, 0.0f, WHITE);

	//HpBar
	Novice::DrawBox(640, 700, int(hp_ / hpMax_ * -150), 20, 0.0f, RED, kFillModeSolid);
	Novice::DrawBox(640, 700, int(hp_ / hpMax_ * 150), 20, 0.0f,RED, kFillModeSolid);
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

void Player::OnCollision(const Enemy* enemy)
{
	(void)enemy;
	hp_ -= 10.0f;
	if (hp_ <= 0.0f) {
		isAlive_ = false;
	}
}

