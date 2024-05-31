#include "TitleScene.h"

void TitleScene::Init()
{

}

void TitleScene::Update(char keys[], char preKeys[])
{
	//Spaceキーを押すとステージ画面に移行
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	//debug用
	Novice::ScreenPrintf(100, 360, "Title");
	Novice::ScreenPrintf(100, 400, "Press Space To Stage");
}