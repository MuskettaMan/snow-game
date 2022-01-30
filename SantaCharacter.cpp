#include "SantaCharacter.h"
#include <iostream>

SantaCharacter::SantaCharacter(vec2 position, float speed) : Character(position, "assets/character_sheet.png", 7, speed), movementFrameCounter(0)
{
	shooter = new CharacterShooter;
}

SantaCharacter::~SantaCharacter()
{
	delete shooter;
}

void SantaCharacter::NotifyCollision(ColliderType colliderType)
{
	std::cout << "Collision on santa\n";
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

	screen->Line(GetRect()->GetTopLeft().x, GetRect()->GetTopLeft().y, GetRect()->GetTopRight().x, GetRect()->GetTopRight().y, 0xff0000);
	screen->Line(GetRect()->GetTopRight().x, GetRect()->GetTopRight().y, GetRect()->GetBottomRight().x, GetRect()->GetBottomRight().y, 0xff0000);
	screen->Line(GetRect()->GetBottomRight().x, GetRect()->GetBottomRight().y, GetRect()->GetBottomLeft().x, GetRect()->GetBottomLeft().y, 0xff0000);
	screen->Line(GetRect()->GetBottomLeft().x, GetRect()->GetBottomLeft().y, GetRect()->GetTopLeft().x, GetRect()->GetTopLeft().y, 0xff0000);
}