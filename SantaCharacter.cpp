#include "SantaCharacter.h"
#include <iostream>

SantaCharacter::SantaCharacter() : Character("assets/character_sheet.png"), movementFrameCounter(0)
{
	shooter = new CharacterShooter;
}

SantaCharacter::~SantaCharacter()
{
	delete shooter;
}

void SantaCharacter::Shoot() const
{
	shooter->Shoot(GetPosition() + vec2(GetSprite()->GetWidth() / 2, GetSprite()->GetHeight() / 2), GetLastMovingDirection());
}

void SantaCharacter::Update()
{
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