#pragma once

/**
 * \brief Defines an interface for objects that can be updated every frame of the game loop.
 */
class IUpdatable
{
public:
	/**
	 * \brief Destroys the updatable.
	 */
	virtual ~IUpdatable() = default;

	/**
	 * \brief Updates the object.
	 */
	virtual void Update() = 0;
};

