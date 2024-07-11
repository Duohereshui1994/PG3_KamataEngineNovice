#pragma once
#include "Vector2.h"
#include "Novice.h"
class Bullet
{
public:
	Bullet();
	~Bullet();
	void Initialize();
	void Update();
	void Draw();

	Vector2 GetPos()const { return pos_; }

	bool GetIsShot()const { return isShot_; }
	bool SetIsShot(bool isShot) {
		this->isShot_ = isShot;
		return isShot_;
	}
	Vector2 SetPos(Vector2 pos) {
		this->pos_ = pos;
		return pos_;
	}
private:
	//座標
	Vector2 pos_;
	//速度
	float speed_;
	//弾の幅
	float width_;
	//弾の高さ
	float height_;
	//フラグ
	bool isShot_;
	//画像
	int textureBullet_;
};

