#pragma once
#include "Character.h"
#include "GameOverBehaviour.h"

/**
 * \brief A character in the game represented as a santa.
 */
class SantaCharacter : public Character
{
public:
	/**
	 * \brief Creates a new instance of a santa character.
	 * \param position The position to place him at.
	 * \param speed The speed he can move at.
	 * \param collisionHandler The collision handler to manages his collisions.
	 * \param gameOverBehaviour Handles for what happens when the game is over.
	 */
	SantaCharacter(vec2 position, float speed, CollisionHandler* collisionHandler, GameOverBehaviour* gameOverBehaviour);

	/**
	 * \brief Destroys the santa character.
	 */
	~SantaCharacter();

	/**
	 * \brief Notifies when a collision has occurred.
	 * \param colliderType The type of collision that was collided with.
	 */
	void NotifyCollision(ColliderType colliderType) override;

	/**
	 * \brief Draws the character to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen) override;

	/**
	 * \brief Updates the character to move.
	 */
	void Update() override;

	/**
	 * \brief Makes the character shoot a projectile.
	 */
	void Shoot() override;
private:
	/**
	 * \brief Handles the shooting for the character.
	 */
	CharacterShooter* shooter;

	/**
	 * \brief The amount of frames the character has been moving.
	 */
	uint movementFrameCounter;

	/**
	 * \brief Handles what will happen when the game is over.
	 */
	GameOverBehaviour* gameOverBehaviour;
};

