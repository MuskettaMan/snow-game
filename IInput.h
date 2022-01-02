#pragma once
class IInput
{
public:
	virtual ~IInput() = default;
	virtual bool GetUpKeyPressed() = 0;
	virtual bool GetDownKeyPressed() = 0;
	virtual bool GetLeftKeyPressed() = 0;
	virtual bool GetRightKeyPressed() = 0;
	virtual bool GetSpaceKeyPressed() = 0;
};

