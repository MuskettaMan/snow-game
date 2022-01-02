#pragma once
#include "template.h"

class IShooter
{
public:
	virtual ~IShooter() = default;
	virtual void Shoot(Tmpl8::vec2 origin, Tmpl8::vec2 direction) = 0;
};
