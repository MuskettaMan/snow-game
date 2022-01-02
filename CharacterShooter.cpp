#include "CharacterShooter.h"

#include "game.h"

CharacterShooter::CharacterShooter() : fireRate(500), lastFireTime(0)
{
}

void CharacterShooter::Shoot(Tmpl8::vec2 origin, Tmpl8::vec2 direction)
{
	if(lastFireTime + fireRate > Tmpl8::Game::GetTime())
	{
		return;
	}

	Snowball* snowball = new Snowball(origin, direction);
	snowballs.push_back(snowball);
	lastFireTime = Tmpl8::Game::GetTime();
}

void CharacterShooter::Update()
{
	for (int i = 0; i < snowballs.size(); i++)
	{
		if(snowballs[i]->GetStartTime() + 1000 < Tmpl8::Game::GetTime())
		{
			delete snowballs[i];
			snowballs.erase(snowballs.begin() + i);
			continue;
		}
		snowballs[i]->Update();
	}
}

void CharacterShooter::Draw(Tmpl8::Surface* screen)
{
	for (int i = 0; i < snowballs.size(); i++)
	{
		snowballs[i]->Draw(screen);
	}
}
