#include "Character.h"

#include <iostream>

#include "game.h"

void Character::Move(vec2 direction)
{
	isMoving = direction != vec2(0, 0);
	velocity = direction.normalized() * Game::GetDeltaTime() * 0.2f;

	if (isMoving)
		lastMovingDirection = direction;

	if (velocity.x != 0)
		isFacingRight = velocity.x > 0;

	position += velocity;

	shooter->Update();
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

	shooter->Draw(screen);

	sprite->Draw(screen, position.x, position.y);
}

void Character::Shoot() const
{
	shooter->Shoot(position + vec2(sprite->GetWidth() / 2, sprite->GetHeight() / 2), lastMovingDirection);
}

Character::Character() : position(vec2(100, 100)), isMoving(false), lastMovingDirection(vec2(1, 0)), isFacingRight(true), movementFrameCounter(0)
{
	sprite = new Sprite(new Surface("assets/character_sheet.png"), 7);
	sprite->SetFrame(1);
	shooter = new CharacterShooter;
}

Character::~Character()
{
	delete sprite;
	delete shooter;
}
