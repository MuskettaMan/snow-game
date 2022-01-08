#include "Rect.h"

Rect::Rect(vec2 position, vec2 size) : position(position), size(size)
{
}

Rect::Rect() : position(vec2(0, 0)), size(vec2(0, 0))
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

vec2 Rect::GetBottomLeft() const
{
    return vec2(position.x, position.y + size.y);
}

vec2 Rect::GetBottomRight() const
{
    return position + size;
}

float Rect::GetRightSide() const
{
    return position.x + size.x;
}

float Rect::GetLeftSide() const
{
    return position.x;
}

float Rect::GetTopSide() const
{
    return position.y;
}

float Rect::GetBottomSide() const
{
    return position.y + size.y;
}
