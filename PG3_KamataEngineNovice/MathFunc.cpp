#include "MathFunc.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

bool MathFunc::IsCollision(Bullet* bullet, Enemy* enemy)
{
	if (bullet->GetPos().x <= enemy->GetPos().x + enemy->GetWidth() &&
		bullet->GetPos().x + bullet->GetWidth() >= enemy->GetPos().x &&
		bullet->GetPos().y <= enemy->GetPos().y + enemy->GetHeight() &&
		bullet->GetPos().y + bullet->GetHeight() >= enemy->GetPos().y) {
		return true;
	}
	else {
		return false;
	}
}

bool MathFunc::IsCollision(Player* player, Enemy* enemy)
{
	if (player->GetPos().x <= enemy->GetPos().x + enemy->GetWidth() &&
		player->GetPos().x + player->GetWidth() >= enemy->GetPos().x &&
		player->GetPos().y <= enemy->GetPos().y + enemy->GetHeight() &&
		player->GetPos().y + player->GetHeight() >= enemy->GetPos().y) {
		return true;
	}
	else {
		return false;
	}
}

