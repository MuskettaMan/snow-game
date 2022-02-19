#pragma once
#include "Character.h"

/**
 * \brief A collision notification that used for when an enemy collides.
 */
class IEnemyCollisionNotifier
{
public:
	/**
	 * \brief Called when a enemy collided.
	 * \param character The character that was collided with.
	 */
	virtual void NotifyEnemyCollision(const Character& character) const = 0;
};

