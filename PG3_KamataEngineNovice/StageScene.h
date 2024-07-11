#pragma once
#include <list>
#include <thread>
#include "IScene.h"
#include "InputHandle.h"
#include "ICommand.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"

class StageScene : public IScene
{
public:
	StageScene();
	void Init() override;
	void Update(char keys[], char preKeys[]) override;
	void Draw() override;
private:
	//メンバ変数
	InputHandle* inputHandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	Player* player_ = nullptr;
	Background* background_ = nullptr;

	static inline const int enemyCount = 5;
	std::list<Enemy*> enemies_;
};