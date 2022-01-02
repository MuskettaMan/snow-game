#include "Character.h"

#include <iostream>

#include "game.h"

void Character::Move(vec2 direction)
{
	isMoving = direction != vec2(0, 0);
	velocity = direction.normalized() * Game::GetDeltaTime() * speed;

	if (isMoving)
		lastMovingDirection = direction;

	if (velocity.x != 0)
		isFacingRight = velocity.x > 0;

	position += velocity;
}

void Character::Update()
{
}

bool Character::GetIsMoving() const
{
	return isMoving;
}

bool Character::GetIsFacingRight() const
{
	return isFacingRight;
}

vec2 Character::GetPosition() const
{
	return position;
}

vec2 Character::GetLastMovingDirection() const
{
	return lastMovingDirection;
}

Sprite* Character::GetSprite() const
{
	return sprite;
}

void Character::Shoot() {}

Character::Character(char* sheet, int frames, float speed) : position(vec2(100, 100)), isMoving(false), lastMovingDirection(vec2(1, 0)), isFacingRight(true), speed(speed)
{
	sprite = new Sprite(new Surface(sheet), frames);
	sprite->SetFrame(0);
}

Character::~Character()
{
	delete sprite;
}
