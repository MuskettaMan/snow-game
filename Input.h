#pragma once
#include "IInput.h"
class Input : public IInput
{
public:
	bool GetUpKeyPressed() override;
	bool GetDownKeyPressed() override;
	bool GetLeftKeyPressed() override;
	bool GetRightKeyPressed() override;
	void Poll();

private:
	bool up, down, left, right;
};

