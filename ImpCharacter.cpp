#include "ImpCharacter.h"

#include <iostream>

ImpCharacter::ImpCharacter(vec2 position, float speed) : Character(position, "assets/enemy_sheet.png", 16, speed), frameCounter(0)
{
	collider = new Collider(*GetRect(), ColliderType::ENEMY, *this);
}
ImpCharacter::~ImpCharacter()
{

}

void ImpCharacter::NotifyCollision(ColliderType colliderType)
{
	if (colliderType != ColliderType::PROJECTILE)
		return;


}

void ImpCharacter::Draw(Surface* screen)
{
	++frameCounter;

	if (GetIsMoving()) 
	{
		if (GetIsFacingRight())
		{
			GetSprite()->SetFrame(frameCounter / 12 % 4 + 8);
		}
		else
		{
			GetSprite()->SetFrame(frameCounter / 12 % 4 + 12);
		}
	}
	else
	{
		if (GetIsFacingRight())
		{
			GetSprite()->SetFrame(frameCounter / 24 % 4);
		}
		else
		{
			GetSprite()->SetFrame(frameCounter / 24 % 4 + 4);
		}
	}
	GetSprite()->Draw(screen, GetPosition().x, GetPosition().y);
}
