#pragma once
#include "Vector2.h"
#include "Novice.h"
class Enemy
{
public:
	//コンストラクタ
	Enemy();

	void Init();
	void Update();
	void Draw();

	//set flag
	bool setIsAlive(bool value) { this->isAlive_ = value; }

private:
	//座標
	Vector2 pos_;
	//速度
	float speed_;
	//幅
	float width;
	//高さ
	float height;
	//フラグ
	bool isAlive_;
	//蘇る時間
	int respawnTimer_;
	//画像
	int textureEnemy_;
};

