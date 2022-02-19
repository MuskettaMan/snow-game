#pragma once
#include "Character.h"

class IEnemyCollisionNotifier
{
public:
	virtual void NotifyEnemyCollision(const Character& character) const = 0;
};

