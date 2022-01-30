#include "Rect.h"

vec2 Rect::GetTopLeft() const
{
	return position;
}

vec2 Rect::GetTopRight() const
{
	return vec2(position.x + size.x, position.y);
}

vec2 Rect::GetBottomRight() const
{
	return vec2(position.x + size.x, position.y + size.y);
}

vec2 Rect::GetBottomLeft() const
{
	return vec2(position.x, position.y + size.y);
}
