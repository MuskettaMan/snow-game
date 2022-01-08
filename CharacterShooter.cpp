#include "CharacterShooter.h"

#include "game.h"

using namespace Tmpl8;

CharacterShooter::CharacterShooter(ColliderSystem& colliderSystem) : fireRate(500), lastFireTime(0), colliderSystem(colliderSystem)
{
}

CharacterShooter::~CharacterShooter()
{
}

void CharacterShooter::Shoot(vec2 origin, vec2 direction)
{
	if(lastFireTime + fireRate > Game::GetTime())
	{
		return;
	}

	Snowball* snowball = new Snowball(origin, direction);
	snowballs.push_back(snowball);
	colliderSystem.Register(snowball->GetCollider());
	lastFireTime = Game::GetTime();
}

void CharacterShooter::Update()
{
	for (int i = 0; i < snowballs.size(); i++)
	{
		if(snowballs[i]->GetStartTime() + 1000 < Game::GetTime())
		{
			colliderSystem.Unregister(snowballs[i]->GetCollider());
			delete snowballs[i];
			snowballs.erase(snowballs.begin() + i);
			continue;
		}
		snowballs[i]->Update();
	}
}

void CharacterShooter::Draw(Surface* screen)
{
	for (int i = 0; i < snowballs.size(); i++)
	{
		snowballs[i]->Draw(screen);
	}
}
