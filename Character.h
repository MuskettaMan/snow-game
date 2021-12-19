#pragma once
#include "surface.h"
#include "template.h"

using namespace Tmpl8;

class Character
{
public:
	void Move(vec2 direction);
	void Draw(Surface* screen);
	Character();
	~Character();
private:
	vec2 position;
	Sprite* sprite;
	bool isMoving;
	vec2 velocity;
	bool isFacingRight;
	uint movementFrameCounter;
};

