#pragma once
#include <vector>

#include "IShooter.h"
#include "Snowball.h"
#include "IUpdatable.h"

class CharacterShooter : IShooter, public IUpdatable
{
public:
	CharacterShooter();
	void Shoot(Tmpl8::vec2 origin, Tmpl8::vec2 direction) override;
	void Update();
	void Draw(Tmpl8::Surface* screen);

private:
	std::vector<Snowball*> snowballs;
	float fireRate;
	float lastFireTime;
};

