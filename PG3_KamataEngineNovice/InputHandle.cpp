#include "InputHandle.h"
#include "Novice.h"

ICommand* InputHandle::HandleInput()
{
	//move
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_;
	}
	else if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}
	else if (Novice::CheckHitKey(DIK_W)) {
		return pressKeyW_;
	}
	else if (Novice::CheckHitKey(DIK_S)) {
		return pressKeyS_;
	}

	//shoot
	if (Novice::CheckHitKey(DIK_J)) {
		return pressKeyJ_;
	}
	return nullptr;
}

void InputHandle::AssignMoveLeftCommand2PressKeyA()
{
	ICommand* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

void InputHandle::AssignMoveRightCommand2PressKeyD()
{
	ICommand* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}

void InputHandle::AssignMoveUpCommand2PressKeyW()
{
	ICommand* command = new MoveUpCommand();
	this->pressKeyW_ = command;
}

void InputHandle::AssignMoveDownCommand2PressKeyS()
{
	ICommand* command = new MoveDownCommand();
	this->pressKeyS_ = command;
}

void InputHandle::AssignShootCommand2PressKeyJ()
{
	ICommand* command = new ShootCommand();
	this->pressKeyJ_ = command;
}
