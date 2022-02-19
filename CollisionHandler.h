#pragma once
#include <vector>
#include <algorithm>

#include "Collider.h"
#include "IUpdatable.h"

/**
 * \brief Aggregates collisions over the entire game and does the bounds checking.
 */
class CollisionHandler : public IUpdatable
{
public:
	/**
	 * \brief Creates a new collision handler.
	 */
	CollisionHandler();

	/**
	 * \brief Destroys a collision handler.
	 */
	~CollisionHandler();

	/**
	 * \brief Does all the bounds checking on the colliders.
	 */
	void Update() override;

	/**
	 * \brief Registers a new collider for checking collisions.
	 * \param collider The collider to register.
	 */
	void Register(Collider* collider) const;

	/**
	 * \brief Deregister a collider from the handler so it isn't checked anymore for collision..
	 * \param collider The collider to deregister.
	 */
	void Deregister(Collider* collider);

private:
	/**
	 * \brief All the colliders aggregated in the handler.
	 */
	std::vector<Collider*>* colliders;
};

