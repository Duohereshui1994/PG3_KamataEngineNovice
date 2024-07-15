#pragma once
#include <list>
#include <thread>
#include "IScene.h"
#include "InputHandle.h"
#include "ICommand.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "MathFunc.h"

class StageScene : public IScene
{
public:
	StageScene();
	~StageScene();
	void Init() override;
	void Update(char keys[], char preKeys[]) override;
	void Draw() override;
	//当たり判定
	void CheckCollisions();
private:
	//メンバ変数
	InputHandle* inputHandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	//数学関数
	MathFunc* math_ = nullptr;
	//背景
	Background* background_ = nullptr;
	//プレイヤー
	Player* player_ = nullptr;
	//敵
	static inline const int enemyCount = 5;
	std::list<Enemy*> enemies_;
	//スコア
	int score_ = 0;

};