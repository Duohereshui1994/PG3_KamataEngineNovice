#pragma once

class Player;
class Enemy;
class Bullet;

class MathFunc
{
public:

	bool IsCollision(Player* player, Enemy* enemy);

	bool IsCollision(Bullet* bullet, Enemy* enemy);
};

