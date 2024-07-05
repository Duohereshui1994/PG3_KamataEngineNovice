#pragma once
#include <vector>
#include "Vector2.h"
#include "Novice.h"
#include "Bullet.h"
class Player
{
public:
	std::vector<Bullet> bullets_;
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
	void Shoot();

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
	//HP
	float hpMax_;
	float hp_;
	//攻撃の間隔
	int CD;
};

