#pragma once
#include "ColliderType.h"
#include "CollisionNotifier.h"
#include "Rect.h"

/**
 * \brief Defines a collider that can be used with other instances to check for overlaps.
 */
class Collider
{
public:
	/**
	 * \brief Creates a new collider instance.
	 * \param rect The bounding box of the collider.
	 * \param colliderType The type this collider represents.
	 * \param notifier Notifies when collisions have occurred.
	 */
	Collider(const Rect& rect, ColliderType colliderType, ICollisionNotifier& notifier);

	/**
	 * \brief Whether this collider is colliding with another collider.
	 * \param collider The other collider to check with.
	 * \return Whether there is an overlap.
	 */
	bool Collides(const Collider& collider) const;

private:
	/**
	 * \brief The bounding box of the collider.
	 */
	const Rect& rect;

	/**
	 * \brief The type this collider represents.
	 */
	ColliderType colliderType;

	/**
	 * \brief Notifies when collisions have occurred.
	 */
	ICollisionNotifier& notifier;
};

