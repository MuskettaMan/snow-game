#include "Input.h"

#include <windows.h>

bool Input::GetUpKeyPressed()
{
	return up;
}

bool Input::GetDownKeyPressed()
{
	return down;
}

bool Input::GetLeftKeyPressed()
{
	return left;
}

bool Input::GetRightKeyPressed()
{
	return right;
}

void Input::Poll()
{
	left = GetAsyncKeyState(VK_LEFT);
	right = GetAsyncKeyState(VK_RIGHT);
	up = GetAsyncKeyState(VK_UP);
	down = GetAsyncKeyState(VK_DOWN);
}
