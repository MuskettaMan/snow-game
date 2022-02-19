#pragma once
#include "template.h"

using namespace Tmpl8;

/**
 * \brief Defines shooting behaviour.
 */
class IShooter
{
public:
	/**
	 * \brief Destroys the shooting behaviour.
	 */
	virtual ~IShooter() = default;

	/**
	 * \brief Shoots from somewhere in a direction.
	 * \param origin The starting place of the shot.
	 * \param direction The direction to shoot to.
	 */
	virtual void Shoot(vec2 origin, vec2 direction) = 0;
};
