#pragma once
#include "ColliderType.h"

class Present;

/**
 * \brief A collision callback that also passes the reference to the present that was collided with.
 */
class IPresentCollisionNotifier
{
public:
	/**
	 * \brief Notifies when a collision occurred with a present.
	 * \param present The present that was collided with.
	 * \param colliderType The type of collision that happened.
	 */
	virtual void NotifyPresentCollision(Present& present, ColliderType colliderType) = 0;
};

