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
	int textureTitle = Novice::LoadTexture("./RS/title.png");

	Novice::DrawSprite(0, 0, textureTitle, 1, 1, 0.0f, WHITE);
}