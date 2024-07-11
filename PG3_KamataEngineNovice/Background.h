#pragma once
#include "Vector2.h"
#include "Novice.h"
class Background
{
public:
	//コンストラクタ
	Background();

	void Init();
	void Update();
	void Draw();
private:
	//座標
	Vector2 pos1_;
	Vector2 pos2_;
	Vector2 pos3_;
	//画像
	int textureBg1_;
	int textureBg2_;
	int textureBg3_;
};

