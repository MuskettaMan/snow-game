#pragma once
#include <vector>

#include "template.h"

using namespace Tmpl8;

class IPlacementGenerator
{
public:
	virtual vec2 GetPlacement() const = 0;
};

