#include "Background.h"

Background::Background()
{
	pos1_ = { 0.0f,0.0f };
	pos2_ = { 0.0f,0.0f };
	pos3_ = { 0.0f,0.0f };
	textureBg1_ = Novice::LoadTexture("./RS/bg1.png");
	textureBg2_ = Novice::LoadTexture("./RS/bg2.png");
	textureBg3_ = Novice::LoadTexture("./RS/bg3.png");
}

void Background::Init()
{
	pos1_ = { 0.0f,0.0f };
	pos2_ = { 0.0f,0.0f };
	pos3_ = { 0.0f,0.0f };
}

void Background::Update()
{
	pos1_ += {-2.0f, 0.0f};
	pos2_ += {-1.0f, 0.0f};
	pos3_ += {-0.5f, 0.0f};

	if (pos1_.x <= -1280.0f) {
		pos1_.x = 0.0f;
	}
	if (pos2_.x <= -1280.0f) {
		pos2_.x = 0.0f;
	}
	if (pos3_.x <= -1280.0f) {
		pos3_.x = 0.0f;
	}
}

void Background::Draw()
{
	Novice::DrawSprite(int(pos1_.x), int(pos1_.y), textureBg1_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(int(pos1_.x + 1280.0f), int(pos1_.y), textureBg1_, 1, 1, 0.0f, WHITE);

	Novice::DrawSprite(int(pos2_.x), int(pos2_.y), textureBg2_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(int(pos2_.x + 1280.0f), int(pos2_.y), textureBg2_, 1, 1, 0.0f, WHITE);

	Novice::DrawSprite(int(pos3_.x), int(pos3_.y), textureBg3_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(int(pos3_.x + 1280.0f), int(pos3_.y), textureBg3_, 1, 1, 0.0f, WHITE);
}
