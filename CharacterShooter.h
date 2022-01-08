#pragma once
#include <vector>

#include "IShooter.h"
#include "Snowball.h"
#include "IUpdatable.h"
#include "ColliderSystem.h"

using namespace Tmpl8;

class CharacterShooter : IShooter, public IUpdatable
{
public:
	CharacterShooter(ColliderSystem& colliderSystem);
	~CharacterShooter();
	void Shoot(vec2 origin, vec2 direction) override;
	void Update();
	void Draw(Surface* screen);

private:
	ColliderSystem& colliderSystem;
	std::vector<Snowball*> snowballs;
	float fireRate;
	float lastFireTime;
};

