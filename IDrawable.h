#pragma once
#include "surface.h"
#include "template.h"

using namespace Tmpl8;

/**
 * \brief Defines an interface for objects that can be drawn.
 */
class IDrawable
{
public:
	/**
	 * \brief Destroys the drawable.
	 */
	virtual ~IDrawable() = default;

	/**
	 * \brief Draws the object to the screen.
	 * \param screen The screen to draw to.
	 */
	virtual void Draw(Surface* screen) = 0;
};

