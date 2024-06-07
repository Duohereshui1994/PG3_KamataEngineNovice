#pragma once
#include "Selector.h"
#include "IStageSceneCommand.h"
class StageSceneInputHandler
{
private:
	char keys_[255] = { 0 };
	char prekeys_[255] = { 0 };

	Selector* selector_;
	Unit* selectedUnit_;

public:
	StageSceneInputHandler();
	void UpdateKeyState();

	IStageSceneCommand* SelectorHandleInput(Selector* selector);
	IStageSceneCommand* UnitHandleInput(Unit* unit);

	bool CheckUndoStatus();
};

