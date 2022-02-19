#pragma once
#include "CharacterShooter.h"
#include "Collider.h"
#include "surface.h"
#include "template.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Rect.h"

using namespace Tmpl8;

/**
 * \brief The base for all entities that can be moved and interacted with throughout the game.
 */
class Character : public IDrawable, public IUpdatable, public ICollisionNotifier
{
public:
	/**
	 * \brief Creates a new in a certain position with the gives sprites sheet and movement speed.
	 * \param position The position to place the character.
	 * \param sheet The sheet to use as character sprite.
	 * \param frames The amount of frames in the sheet.
	 * \param speed The speed the character can move at.
	 */
	Character(vec2 position, char* sheet, int frames, float speed);

	/**
	 * \brief Destroys the character.
	 */
	~Character();

	/**
	 * \brief Moves the character in the given direction.
	 * \param direction The direction to move the character in.
	 */
	virtual void Move(vec2 direction);

	/**
	 * \brief Makes the character shoot a projectile.
	 */
	virtual void Shoot();

	/**
	 * \brief Draws the character to the screen.
	 * \param screen The screen to draw the character to.
	 */
	virtual void Draw(Surface* screen) = 0;

	/**
	 * \brief The update method to fire every frame.
	 */
	virtual void Update();

	/**
	 * \brief Gets called when the character collides with another collider.
	 * \param colliderType The type of collider that was collided with.
	 */
	virtual void NotifyCollision(ColliderType colliderType) override = 0;

	/**
	 * \brief Whether the character is moving.
	 * \return Whether the character is moving.
	 */
	bool GetIsMoving() const;

	/**
	 * \brief Whether the character is facing right.
	 * \return Whether the character is facing right.
	 */
	bool GetIsFacingRight() const;

	/**
	 * \brief The position the character is currently at.
	 * \return The position the character is currently at.
	 */
	vec2 GetPosition() const;

	/**
	 * \brief The last direction the character was moving in.
	 * \return The last direction the character was moving in.
	 */
	vec2 GetLastMovingDirection() const;

	/**
	 * \brief The bounding rectangle of the character.
	 * \return The bounding rectangle of the character.
	 */
	Rect* GetRect() const;

	/**
	 * \brief The collider of the character.
	 * \return The collider of the character.
	 */
	Collider& GetCollider() const;
protected:
	/**
	 * \brief A pointer to the sprite of the character.
	 * \return A pointer to the sprite of the character.
	 */
	Sprite* GetSprite() const;

	/**
	 * \brief The collider of the character.
	 */
	Collider* collider;
private:
	/**
	 * \brief The bounding box of the character.
	 */
	Rect* rect;

	/**
	 * \brief The position of the character on the screen relative to the top-left window origin.
	 */
	vec2 position;

	/**
	 * \brief The sprite of the character to draw.
	 */
	Sprite* sprite;

	/**
	 * \brief Whether the player is moving.
	 */
	bool isMoving;

	/**
	 * \brief The movement velocity of the character.
	 */
	vec2 velocity;

	/**
	 * \brief The direction of the last moving frame.
	 */
	vec2 lastMovingDirection;

	/**
	 * \brief Whether the character is facing the right direction.
	 */
	bool isFacingRight;

	/**
	 * \brief The speed the character can walk at.
	 */
	float speed;
};

