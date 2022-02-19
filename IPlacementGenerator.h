#pragma once
#include <vector>

#include "template.h"

using namespace Tmpl8;

/**
 * \brief Defines an interface for getting a placement.
 */
class IPlacementGenerator
{
public:
	/**
	 * \brief Should generate a placement.
	 * \return The position of the placement.
	 */
	virtual vec2 GetPlacement() const = 0;
};

