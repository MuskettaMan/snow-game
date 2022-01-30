#include "CharacterShooter.h"

#include "game.h"

CharacterShooter::CharacterShooter(CollisionHandler* collisionHandler) : fireRate(500), lastFireTime(0), collisionHandler(collisionHandler)
{
}

void CharacterShooter::Shoot(vec2 origin, vec2 direction)
{
	if(lastFireTime + fireRate > Game::GetTime())
	{
		return;
	}

	Snowball* snowball = new Snowball(origin, direction, *this);
	snowballs.push_back(snowball);
	collisionHandler->Register(&snowball->GetCollider());
	lastFireTime = Game::GetTime();
}

void CharacterShooter::Update()
{
	for (int i = 0; i < snowballs.size(); i++)
	{
		if(snowballs[i]->GetStartTime() + 1000 < Game::GetTime())
		{
			RemoveSnowball(*snowballs[i]);
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

void CharacterShooter::NotifySnowballCollision(Snowball& snowball, ColliderType colliderType)
{
	if (colliderType != ColliderType::ENEMY)
		return;
	RemoveSnowball(snowball);
}

void CharacterShooter::RemoveSnowball(const Snowball& snowball)
{
	collisionHandler->Deregister(&snowball.GetCollider());
	snowballs.erase(std::find(snowballs.begin(), snowballs.end(), &snowball));
	delete &snowball;
}
