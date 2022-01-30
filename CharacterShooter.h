#pragma once
#include <vector>

#include "CollisionHandler.h"
#include "IShooter.h"
#include "Snowball.h"
#include "IUpdatable.h"

class CharacterShooter : public IShooter, public IUpdatable, public ISnowballCollisionNotifier
{
public:
	CharacterShooter(CollisionHandler* collisionHandler);
	void Shoot(vec2 origin, vec2 direction) override;
	void Update() override;
	void Draw(Surface* screen);
	void NotifySnowballCollision(Snowball& snowball, ColliderType colliderType) override;

private:
	void RemoveSnowball(const Snowball& snowball);

	std::vector<Snowball*> snowballs;
	float fireRate;
	float lastFireTime;
	CollisionHandler* collisionHandler;
};

