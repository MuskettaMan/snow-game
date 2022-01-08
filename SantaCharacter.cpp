#include "SantaCharacter.h"
#include <iostream>

SantaCharacter::SantaCharacter(float speed) : Character("assets/character_sheet.png", 7, speed, vec2(100, 100)), movementFrameCounter(0)
{
	shooter = new CharacterShooter;
}

SantaCharacter::~SantaCharacter()
{
	delete shooter;
}

void SantaCharacter::Shoot()
{
	shooter->Shoot(GetPosition() + vec2(GetSprite()->GetWidth() / 2, GetSprite()->GetHeight() / 2), GetLastMovingDirection());
}

void SantaCharacter::Update()
{
	Character::Update();
	shooter->Update();
}

void SantaCharacter::Draw(Surface* screen)
{
	if (GetIsMoving())
	{
		++movementFrameCounter;
		int frameRange = movementFrameCounter / 12 % 3;
		if (GetIsFacingRight())
			GetSprite()->SetFrame(frameRange + 4);
		else
			GetSprite()->SetFrame(frameRange + 1);
	}
	else
	{
		GetSprite()->SetFrame(GetIsFacingRight() ? 0 : 1);
	}

	shooter->Draw(screen);

	GetSprite()->Draw(screen, GetPosition().x, GetPosition().y);
}