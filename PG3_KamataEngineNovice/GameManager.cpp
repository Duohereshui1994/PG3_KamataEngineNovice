#include "GameManager.h"

GameManager::GameManager() {
	//各シーンの配列
	_sceneArr[TITLE] = std::make_unique<TitleScene>();
	_sceneArr[STAGE] = std::make_unique<StageScene>();
	_sceneArr[CLEAR] = std::make_unique<ClearScene>();
	//現在のシーン
	_currentSceneNo = TITLE;
}

GameManager::~GameManager() {}

int GameManager::run(char keys[], char preKeys[]) {


	while (Novice::ProcessMessage() == 0) {


		Novice::BeginFrame();//フレーム開始



		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		//シーンのチェック
		_prevSceneNo = _currentSceneNo;
		_currentSceneNo = _sceneArr[_currentSceneNo]->GetSceneNo();

		//シーン変更チェック
		if (_prevSceneNo != _currentSceneNo) {
			_sceneArr[_currentSceneNo]->Init();
		}

		//更新処理
		_sceneArr[_currentSceneNo]->Update(keys, preKeys);//シーンごとの更新処理

		//描画処理
		_sceneArr[_currentSceneNo]->Draw();

		Novice::EndFrame(); //フレーム終了

		//ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}

	}
	return 0;
}