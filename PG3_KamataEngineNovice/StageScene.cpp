#include "StageScene.h"

StageScene::StageScene()
{
}

StageScene::~StageScene()
{
	delete inputHandler_;
	delete background_;
	delete player_;
	for (Enemy* enemy : enemies_) {
		delete enemy;
	}
	enemies_.clear();
}

void StageScene::Init()
{
	//今の敵を削除
	for (Enemy* enemy : enemies_) {
		delete enemy;
	}
	enemies_.clear();

	//初期化
	inputHandler_ = new InputHandle();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveUpCommand2PressKeyW();
	inputHandler_->AssignMoveDownCommand2PressKeyS();
	inputHandler_->AssignShootCommand2PressKeyJ();
	//スコア初期化
	score_ = 0;
	//背景初期化
	background_ = new Background();
	background_->Init();
	//プレイヤー初期化
	player_ = new Player();
	player_->Init();
	//敵初期化
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
		//sceneNo = CLEAR;
	}

	if (score_ == 10) {
		sceneNo = CLEAR;
	}

	if (player_->GetIsAlive() == false) {
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

	//当たり判定
	CheckCollisions();
}

void StageScene::Draw()
{
	//文字
	Novice::ScreenPrintf(0, 700, "WASD : MOVE     J : SHOOT");
	Novice::ScreenPrintf(800, 700, "SCORE : %d", score_);
	//背景描画
	background_->Draw();
	//プレイヤー描画
	player_->Draw();
	//敵描画
	for (Enemy* enemy : enemies_) {
		enemy->Draw();
	}
}




void StageScene::CheckCollisions()
{

	//プレイヤーと敵の当たり判定
	for (Enemy* enemy : enemies_) {
		if (enemy->GetIsAlive() == true) {
			if (math_->IsCollision(player_, enemy)) {
				player_->OnCollision(enemy);
				enemy->OnCollision(player_);
			}
		}
	}

	//bulletと敵の当たり判定
	for (auto& bullet : player_->bullets_) {
		if (bullet.GetIsShot() == true) {
			for (Enemy* enemy : enemies_) {
				if (enemy->GetIsAlive() == true) {
					if (math_->IsCollision(&bullet, enemy)) {
						enemy->OnCollision(&bullet);
						bullet.SetIsShot(false);
						score_ += 1;
					}
				}
			}
		}
	}
}