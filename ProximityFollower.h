#pragma once
#include "Character.h"

/**
 * \brief Manages a character to follow a target within a certain proximity.
 */
class ProximityFollower : public IUpdatable
{
public:
	/**
	 * \brief Creates a new instance that can manage a character to follow a certain to target within a given proximity.
	 * \param character The character to make follow.
	 * \param target The target to follow.
	 * \param proximityDistance The distance within the following happens.
	 */
	ProximityFollower(Character* character, Character* target, float proximityDistance);

	/**
	 * \brief Moves the character if conditions are met.
	 */
	void Update();
private:
	/**
	 * \brief The character to make follow.
	 */
	Character* character;

	/**
	 * \brief The target to follow.
	 */
	Character* target;

	/**
	 * \brief The distance within the following happens.
	 */
	float proximityDistance;
};

