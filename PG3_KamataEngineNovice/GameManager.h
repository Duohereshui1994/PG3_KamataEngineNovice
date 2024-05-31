#pragma once

#include <memory>// for unique_ptr
#include "IScene.h"//シーンの基底クラスに加えて
#include "StageScene.h"//各シーンを読み込む
#include "TitleScene.h"
#include "ClearScene.h"


class GameManager
{
private:
	//シーンを保持するメンバー変数
	std::unique_ptr<IScene> _sceneArr[3];

	//どのステージを呼び出すかを管理する変数
	int _currentSceneNo;//現在のシーン
	int _prevSceneNo;//前のシーン



public:
	//コンストラクタ
	GameManager();

	//デストラクタ
	~GameManager();

	//この関数でゲームループを呼び出す
	int run(char keys[], char preKeys[]);
};