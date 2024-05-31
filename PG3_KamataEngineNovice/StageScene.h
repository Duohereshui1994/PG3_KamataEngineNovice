#pragma once
#include "IScene.h"
#include "InputHandle.h"
#include "ICommand.h"
#include "Player.h"

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
};