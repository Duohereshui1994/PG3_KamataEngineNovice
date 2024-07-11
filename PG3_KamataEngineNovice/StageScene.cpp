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


	background_ = new Background();

	player_ = new Player();

	for (auto i = 0; i < enemyCount; ++i) {
		Enemy* newEnemy = new Enemy();
		newEnemy->Init();
		enemies_.push_back(newEnemy);
	}

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


	// スレッドで　player_ と background_　更新 
	std::thread backgroundThread(&Background::Update, background_);
	std::thread playerThread(&Player::Update, player_);

	// wait for thread complete
	backgroundThread.join();
	playerThread.join();

	for (Enemy* enemy : enemies_) {
		enemy->Update();
	}
}

void StageScene::Draw()
{
	//debug用
	Novice::ScreenPrintf(100, 360, "Stage");
	Novice::ScreenPrintf(100, 400, "Press Space to Clear");
	Novice::ScreenPrintf(100, 440, "Press A or D to Move");

	background_->Draw();
	player_->Draw();

	for (Enemy* enemy : enemies_) {
		enemy->Draw();
	}
}