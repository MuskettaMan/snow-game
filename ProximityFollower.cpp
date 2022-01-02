#include "ProximityFollower.h"

ProximityFollower::ProximityFollower(Character* character, Character* target, float proximityDistance) : character(character), target(target), proximityDistance(proximityDistance)
{
}

void ProximityFollower::Update()
{
	vec2 direction = vec2(0, 0);
	float distance = vec2::distance(character->GetPosition(), target->GetPosition());
	if (distance < proximityDistance) {
		direction = target->GetPosition() - character->GetPosition();
	}
	character->Move(direction);
}
