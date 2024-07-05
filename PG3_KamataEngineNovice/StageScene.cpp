#include "StageScene.h"

StageScene::StageScene()
{
}

void StageScene::Init()
{
	//初期化
	inputHandler_ = new InputHandle();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveUpCommand2PressKeyW();
	inputHandler_->AssignMoveDownCommand2PressKeyS();
	inputHandler_->AssignShootCommand2PressKeyJ();

	player_ = new Player();
}

void StageScene::Update(char keys[], char preKeys[])
{
	//Spaceキーを押すとクリア画面に移行
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo = CLEAR;
	}

	//入力処理
	iCommand_ = inputHandler_->HandleInput();

	if (this->iCommand_) {
		iCommand_->Exec(*player_);
	}

	player_->Update();
}

void StageScene::Draw()
{
	//debug用
	Novice::ScreenPrintf(100, 360, "Stage");
	Novice::ScreenPrintf(100, 400, "Press Space to Clear");
	Novice::ScreenPrintf(100, 440, "Press A or D to Move");
	player_->Draw();
}