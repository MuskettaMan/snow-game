#pragma once
#include <vector>

#include "CollisionHandler.h"
#include "IShooter.h"
#include "Snowball.h"
#include "IUpdatable.h"

/**
 * \brief Provides a shooting behaviour for the player.
 */
class CharacterShooter : public IShooter, public IUpdatable, public ISnowballCollisionNotifier
{
public:
	/**
	 * \brief Creates a new shooting behaviour.
	 * \param collisionHandler The collision handler to register snowballs to.
	 */
	CharacterShooter(CollisionHandler* collisionHandler);

	/**
	 * \brief Destroys all the composed snowballs.
	 */
	~CharacterShooter() override;

	/**
	 * \brief Shoots a snowball from a placement in a direction.
	 * \param origin The initial position of the snowball.
	 * \param direction The direction of the snowball.
	 */
	void Shoot(vec2 origin, vec2 direction) override;

	/**
	 * \brief Updates the all the composed snowballs.
	 */
	void Update() override;

	/**
	 * \brief Draws all the snowballs to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen);

	/**
	 * \brief Notifies of a snowball collision.
	 * \param snowball The snowball that had the collision.
	 * \param colliderType The type of collision.
	 */
	void NotifySnowballCollision(Snowball& snowball, ColliderType colliderType) override;

private:
	/**
	 * \brief Removes a snowball.
	 * \param snowball The snowball to remove.
	 */
	void RemoveSnowball(const Snowball& snowball);

	/**
	 * \brief All the composed snowballs.
	 */
	std::vector<Snowball*> snowballs;

	/**
	 * \brief The fire rate of the shooting behaviour.
	 */
	float fireRate;

	/**
	 * \brief The time of the last shot.
	 */
	float lastFireTime;

	/**
	 * \brief The collision handler for registering snowballs to.
	 */
	CollisionHandler* collisionHandler;
};

