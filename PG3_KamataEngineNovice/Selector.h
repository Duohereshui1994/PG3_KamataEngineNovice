#pragma once
#include "Unit.h"
enum Mode {
	SELECTOR,
	UNIT,
};
class Selector
{
private:
	int mapX_;
	int mapY_;
	int mapSize_;

	int selectMode_;

	Unit* unit_;
	Unit* selectedUnit_;

public:
	Selector();

	void Init();
	void Update();
	void Draw();

	void Move();
	void SelectUnit();

	int GetMapX() { return mapX_; }
	int GetMapY() { return mapY_; }
	int GetMapSize() { return mapSize_; }

	int GetSelectMode() { return selectMode_; }
};

