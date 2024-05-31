#include "StageScene.h"

void StageScene::Init()
{
}

void StageScene::Update(char keys[], char preKeys[])
{
	//Spaceキーを押すとクリア画面に移行
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo = CLEAR;
	}
}

void StageScene::Draw()
{
	//debug用
	Novice::ScreenPrintf(100, 360, "Stage");
}