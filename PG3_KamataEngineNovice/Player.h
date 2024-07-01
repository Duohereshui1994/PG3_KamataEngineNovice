#pragma once
#include "Vector2.h"
#include "Novice.h"
class Player
{
public:
	//コンストラクタ
	Player();

	void Init();
	void Update();
	void Draw();

	//メンバ変数
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

private:
	//座標
	Vector2 pos_;
	//速度
	float speed_;
};

