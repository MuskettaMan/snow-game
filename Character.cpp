#include "Character.h"

#include <iostream>

#include "game.h"
#include "ColliderLibrary.h"

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
	rect->position = position;
	rect->size = vec2(sprite->GetWidth(), sprite->GetHeight());
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

const Rect& Character::GetRect() const
{
	return *rect;
}

const Collider& Character::GetCollider() const
{
	return *collider;
}

Sprite* Character::GetSprite() const
{
	return sprite;
}

void Character::Shoot() {}

Character::Character(char* sheet, int frames, float speed, vec2 position) : position(position), isMoving(false), lastMovingDirection(vec2(1, 0)), isFacingRight(true), speed(speed)
{
	sprite = new Sprite(new Surface(sheet), frames);
	rect = new Rect(position, vec2(sprite->GetWidth(), sprite->GetHeight()));
	collider = new Collider(*rect);
	sprite->SetFrame(0);
}

Character::~Character()
{
	delete collider;
	delete rect;
	delete sprite;
}
