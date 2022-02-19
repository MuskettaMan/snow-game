#pragma once
#include <random>

#include "Character.h"
#include "IPlacementGenerator.h"

/**
 * \brief A placement generator that randomly chooses placements.
 */
class RandomPlacementGenerator : public IPlacementGenerator
{
public:
	/**
	 * \brief Creates a new placement generator.
	 * \param character The character that no presents should spawn close to.
	 */
	RandomPlacementGenerator(const Character& character);

	/**
	 * \brief Retrieves a random placement.
	 * \return A random placement.
	 */
	vec2 GetPlacement() const override;

private:
	/**
	 * \brief The character that no presents should spawn close to.
	 */
	const Character& character;

	/**
	 * \brief The radius from which presents should now spawn around the character.
	 */
	int radius = 150;
};

