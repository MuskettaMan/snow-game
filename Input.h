#pragma once
#include "IInput.h"
#include "IUpdatable.h"
class Input : public IInput, public IUpdatable
{
public:
	bool GetUpKeyPressed() override;
	bool GetDownKeyPressed() override;
	bool GetLeftKeyPressed() override;
	bool GetRightKeyPressed() override;
	bool GetSpaceKeyPressed() override;
	void Update() override;

private:
	bool up, down, left, right, space;
};

