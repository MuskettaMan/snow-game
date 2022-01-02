#include "ImpCharacter.h"

ImpCharacter::ImpCharacter(float speed) : Character("assets/enemy_sheet.png", 16, speed), frameCounter(0)
{

}
ImpCharacter::~ImpCharacter()
{

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
