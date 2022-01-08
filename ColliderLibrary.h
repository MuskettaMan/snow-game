#pragma once
#include "template.h"
#include "Rect.h"

using namespace Tmpl8;

class ColliderLibrary
{
public:
	inline static bool PointPoint(vec2 pointA, vec2 pointB);

	inline static bool PointCircle(vec2 point, vec2 circleCentre, float circleRadius);

	inline static bool CircleCircle(vec2 circleACentre, float circleARadius, vec2 circleBCentre, float circleBRadius);

	static bool PointRectangle(vec2 point, Rect rect);

	static bool RectRect(const Rect &a, const Rect &b);

	static bool CircleRectangle(Rect rect, vec2 circleCentre, float circleRadius);
};

