#pragma once

class Snowball;

/**
 * \brief Implement on objects that can receive callbacks when they're hit by snowballs.
 */
class ISnowballCollisionNotifier
{
public:
	/**
	 * \brief Notifies of a collision with a snowball.
	 * \param snowball The snowball that was hit with.
	 * \param colliderType The type of collision.
	 */
	virtual void NotifySnowballCollision(Snowball& snowball, ColliderType colliderType) = 0;
};

