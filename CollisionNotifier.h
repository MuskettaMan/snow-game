#pragma once
#include "ColliderType.h"

/**
 * \brief Implement on objects that can receive a collision callback.
 */
class ICollisionNotifier
{
public:
	/**
	 * \brief Notifies the object of a collision.
	 * \param colliderType The type of collider that was collided with.
	 */
	virtual void NotifyCollision(ColliderType colliderType) = 0;
};

