#pragma once
#include <vector>

#include "template.h"

using namespace Tmpl8;

class IPlacementGenerator
{
public:
	virtual vec2 GetPlacement(std::vector<vec2>* positions) const = 0;
};

