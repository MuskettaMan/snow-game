#pragma once
#include "template.h"

using namespace Tmpl8;

class Rect
{
public:
	Rect(vec2 position, vec2 size);
	Rect();
	vec2 GetTopLeft() const;
	vec2 GetTopRight() const;
	vec2 GetBottomLeft() const;
	vec2 GetBottomRight() const;
	float GetRightSide() const;
	float GetLeftSide() const;
	float GetTopSide() const;
	float GetBottomSide() const;
	vec2 position;
	vec2 size;
};

