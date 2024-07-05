#pragma once
#include "ICommand.h"

class InputHandle
{
public:
	ICommand* HandleInput();
	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();
	void AssignMoveUpCommand2PressKeyW();
	void AssignMoveDownCommand2PressKeyS();
	void AssignShootCommand2PressKeyJ();

private:
	ICommand* pressKeyA_;
	ICommand* pressKeyD_;
	ICommand* pressKeyW_;
	ICommand* pressKeyS_;
	ICommand* pressKeyJ_;
};

