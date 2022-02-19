#pragma once
#include <functional>

#include "Character.h"
#include "IEnemyCollisionNotifier.h"

/**
 * \brief The enemy imp character in this game.
 */
class ImpCharacter : public Character
{
public:
	/**
	 * \brief Creates a new imp character at the given position with the given speed and the collision notifier.
	 * \param position The position to spawn the character in.
	 * \param speed The speed the enemy can move.
	 * \param collisionNotifier The collision notifier used to get callback when the enemy collides.
	 */
	ImpCharacter(vec2 position, float speed, const IEnemyCollisionNotifier& collisionNotifier);

	/**
	 * \brief Destroys the enemy.
	 */
	~ImpCharacter();

	/**
	 * \brief Called when the enemy makes a collision.
	 * \param colliderType The collision that was collided with.
	 */
	void NotifyCollision(ColliderType colliderType) override;

	/**
	 * \brief Draws the character to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen) override;
private:
	/**
	 * \brief The amount of frames since initialization.
	 */
	int frameCounter;

	/**
	 * \brief The collision callback.
	 */
	const IEnemyCollisionNotifier& collisionNotifier;
};

