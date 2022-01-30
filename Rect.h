#pragma once
#include "template.h"

using namespace Tmpl8;

class Rect
{
public:
	vec2 position;
	vec2 size;

	vec2 GetTopLeft() const;
	vec2 GetTopRight() const;
	vec2 GetBottomRight() const;
	vec2 GetBottomLeft() const;

private:

};

