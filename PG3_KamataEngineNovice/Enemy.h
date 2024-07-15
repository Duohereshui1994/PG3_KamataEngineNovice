#pragma once
#include "Vector2.h"
#include "Novice.h"

class Bullet;
class Player;

class Enemy
{
public:
	//コンストラクタ
	Enemy();

	//初期化
	void Init();
	//更新
	void Update();
	//描画
	void Draw();
	//位置取得
	Vector2 GetPos() { return pos_; }
	//幅取得
	float GetWidth() { return width_; }
	//高さ取得
	float GetHeight() { return height_; }
	//get flag
	bool GetIsAlive() { return isAlive_; }
	//set flag
	bool SetIsAlive(bool value) { this->isAlive_ = value; }
	//当たり判定
	void OnCollision(const Bullet* bullet);
	void OnCollision(const Player* player);

private:
	//座標
	Vector2 pos_;
	//速度
	float speed_;
	//幅
	float width_;
	//高さ
	float height_;
	//フラグ
	bool isAlive_;
	//蘇る時間
	int respawnTimer_;
	//画像
	int textureEnemy_;
};

