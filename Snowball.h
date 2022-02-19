#pragma once
#include "Collider.h"
#include "ISnowballCollisionNotifier.h"
#include "surface.h"
#include "template.h"

using namespace Tmpl8;

/**
 * \brief A snowball that can be shoot with the CharacterShooter.
 */
class Snowball : public ICollisionNotifier
{
public:
	/**
	 * \brief Creates a new snowball.
	 * \param origin Starting place of the snowball.
	 * \param direction The direction it's traveling.
	 * \param snowballCollisionNotifier The collision notifier for sending collisions.
	 */
	Snowball(vec2 origin, vec2 direction, ISnowballCollisionNotifier& snowballCollisionNotifier);

	/**
	 * \brief Destroys the snowball collider.
	 */
	~Snowball();

	/**
	 * \brief Updates the position of the snowball according to it's velocity.
	 */
	void Update();

	/**
	 * \brief Draws the snowball to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen) const;

	/**
	 * \brief Retrieves the creation time of the snowball.
	 * \return The creation time of the snowball.
	 */
	float GetStartTime();

	/**
	 * \brief Retrieves the collider of the snowball.
	 * \return The collider of the snowball.
	 */
	Collider& GetCollider() const;

	/**
	 * \brief Notifies of a collision.
	 * \param colliderType The type of collision.
	 */
	void NotifyCollision(ColliderType colliderType) override;

private:
	/**
	 * \brief The current position of the snowball.
	 */
	vec2 position;

	/**
	 * \brief The velocity it's traveling.
	 */
	vec2 velocity;

	/**
	 * \brief The sprite of the snowball.
	 */
	Sprite* sprite;

	/**
	 * \brief The bounding box of the snowball.
	 */
	Rect* rect;

	/**
	 * \brief The collider of the snowball.
	 */
	Collider* collider;

	/**
	 * \brief The creation time.
	 */
	float startTime;

	/**
	 * \brief The collision notifier for the snowball.
	 */
	ISnowballCollisionNotifier& snowballCollisionNotifier;
};

