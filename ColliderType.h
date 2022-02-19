#pragma once

/**
 * \brief How an object with a collider identifies itself.
 */
enum class ColliderType
{
	/**
	 * \brief Is a moving object that can be launched.
	 */
	PROJECTILE,

	/**
	 * \brief A hostile NPC.
	 */
	ENEMY,

	/**
	 * \brief A passive NPC.
	 */
	ALLY,

	/**
	 * \brief A collectible.
	 */
	PRESENT
};

