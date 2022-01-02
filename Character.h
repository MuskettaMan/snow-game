#pragma once
#include "CharacterShooter.h"
#include "surface.h"
#include "template.h"

using namespace Tmpl8;

class Character
{
public:
	void Move(vec2 direction);
	void Draw(Surface* screen);
	void Shoot() const;
	Character();
	~Character();
private:
	vec2 position;
	Sprite* sprite;
	bool isMoving;
	vec2 velocity;
	vec2 lastMovingDirection;
	bool isFacingRight;
	uint movementFrameCounter;
	CharacterShooter* shooter;
};

