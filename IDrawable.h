#pragma once
#include "surface.h"
#include "template.h"

class IDrawable
{
public:
	virtual ~IDrawable() = default;
	virtual void Draw(Tmpl8::Surface* screen) = 0;
};

