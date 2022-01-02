#pragma once
#include "Character.h"
class ProximityFollower : public IUpdatable
{
public:
	ProximityFollower(Character* character, Character* target, float proximityDistance);
	void Update();
private:
	Character* character;
	Character* target;
	float proximityDistance;
};

