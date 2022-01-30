#include "Rect.h"

Rect::Rect() : position({0, 0}), size({0, 0})
{
}

Rect::Rect(vec2 position, vec2 size) : position(position), size(size)
{
}

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
