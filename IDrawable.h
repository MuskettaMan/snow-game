#pragma once
#include "template.h"

class IDrawable
{
public:
	virtual void Draw(Tmpl8::Surface* screen) = 0;
};

