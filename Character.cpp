#include "Character.h"

#include <iostream>

#include "game.h"

void Character::Move(vec2 direction)
{
	isMoving = direction != vec2(0, 0);
	velocity = direction * Game::GetDeltaTime() * 0.2f;

	if (velocity.x != 0)
		isFacingRight = velocity.x > 0;

	position += velocity;
}

void Character::Draw(Surface* screen)
{
	if(isMoving)
	{
		++movementFrameCounter;
		int frameRange = movementFrameCounter / 12 % 3;
		if (isFacingRight)
			sprite->SetFrame(frameRange + 4);
		else
			sprite->SetFrame(frameRange + 1);
	}
	else
	{
		sprite->SetFrame(isFacingRight ? 0 : 1);
	}

	sprite->Draw(screen, position.x, position.y);
}

Character::Character() : position(vec2(100, 100)), isFacingRight(true), movementFrameCounter(0)
{
	sprite = new Sprite(new Surface("assets/character_sheet.png"), 7);
	sprite->SetFrame(1);
}

Character::~Character()
{
	delete sprite;
}
