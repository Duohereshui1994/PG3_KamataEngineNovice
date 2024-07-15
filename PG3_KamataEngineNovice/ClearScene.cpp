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
	int textureEnd = Novice::LoadTexture("./RS/end.png");

	Novice::DrawSprite(0, 0, textureEnd, 1, 1, 0.0f, WHITE);
}