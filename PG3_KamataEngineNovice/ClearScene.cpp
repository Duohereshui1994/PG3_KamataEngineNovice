#include "ClearScene.h"

void ClearScene::Init()
{
}

void ClearScene::Update(char keys[], char preKeys[])
{
	//Spaceキーを押すとタイトルに戻る
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
	//debug用
	Novice::ScreenPrintf(100, 360, "Clear");
}