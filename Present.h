#pragma once
#include <functional>

#include "Collider.h"
#include "IDrawable.h"
#include "IPresentCollisionNotifier.h"
#include "PresentFactory.h"
#include "surface.h"

using namespace Tmpl8;

/**
 * \brief A present collectible that the player can collect.
 */
class Present : public IDrawable, public ICollisionNotifier
{
public:
	/**
	 * \brief Creates a new present.
	 * \param pointsToReward The amount of points the present is worth.
	 * \param spriteFrame The frame of the spritesheet to use.
	 * \param position The position of the present.
	 * \param collisionNotifier The collision notifier for notifications.
	 */
	Present(int pointsToReward, int spriteFrame, vec2 position, IPresentCollisionNotifier& collisionNotifier);

	/**
	 * \brief Destroys the present.
	 */
	virtual ~Present();

	/**
	 * \brief The amount of points the present rewards.
	 * \return The amount of points the present rewards.
	 */
	int GetPointsToReward() const;

	/**
	 * \brief Notifies when a collision occurred.
	 * \param colliderType The type of collision.
	 */
	void NotifyCollision (ColliderType colliderType) override;

	/**
	 * \brief Draws the present to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen) override;

	/**
	 * \brief The bounding box of the present.
	 * \return The bounding box of the present. 
	 */
	Rect* GetRect();

	/**
	 * \brief The collider of the present.
	 * \return The collider of the present. 
	 */
	Collider* GetCollider();

private:
	/**
	 * \brief The amount of points the present is worth.
	 */
	int pointsToReward;

	/**
	 * \brief The sprite of the present.
	 */
	Sprite* sprite;

	/**
	 * \brief The bounding box of the present.
	 */
	Rect* rect;

	/**
	 * \brief The collider of the present.
	 */
	Collider* collider;

	/**
	 * \brief The collision notifier for notifications.
	 */
	IPresentCollisionNotifier& collisionNotifier;
};

