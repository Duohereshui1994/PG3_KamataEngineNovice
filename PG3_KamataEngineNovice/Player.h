#pragma once
#include <vector>
#include "Vector2.h"
#include "Novice.h"
#include "Bullet.h"

class Enemy;

class Player
{
public:
	//STLコンテナ　弾の管理
	std::vector<Bullet> bullets_;
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();
	//初期化
	void Init();
	//更新
	void Update();
	//描画
	void Draw();

	//メンバ変数
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void Shoot();

	//位置取得
	Vector2 GetPos() { return pos_; }
	//幅取得
	float GetWidth() { return width_; }
	//高さ取得
	float GetHeight() { return height_; }
	//flag取得
	bool GetIsAlive() { return isAlive_; }
	//当たり判定
	void OnCollision(const Enemy* enemy);

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
	//HP
	float hpMax_;
	float hp_;
	//攻撃の間隔
	int CD_;
	//画像
	int texturePlayer_;
};

