#include "ColliderLibrary.h"

inline bool ColliderLibrary::PointPoint(vec2 pointA, vec2 pointB)
{
	return pointA == pointB;
}

inline bool ColliderLibrary::PointCircle(vec2 point, vec2 circleCentre, float circleRadius)
{
	return (point - circleCentre).length() <= circleRadius;
}

inline bool ColliderLibrary::CircleCircle(vec2 circleACentre, float circleARadius, vec2 circleBCentre, float circleBRadius)
{
	return (circleACentre - circleBCentre).length() <= circleARadius + circleBRadius;
}

bool ColliderLibrary::PointRectangle(vec2 point, Rect rect)
{
	bool isPointRightOfLeftSide = point.x >= rect.GetLeftSide();
	bool isPointLeftOfRightSide = point.x <= rect.GetRightSide();
	bool isPointAboveOfBottomSide = point.y >= rect.GetBottomSide();
	bool isPointBelowOfTopSide = point.y <= rect.GetTopSide();

	return isPointRightOfLeftSide && isPointLeftOfRightSide && isPointAboveOfBottomSide && isPointBelowOfTopSide;
}

bool ColliderLibrary::RectRect(const Rect &a, const Rect &b)
{
	bool rightPassedLeft = a.GetRightSide() >= b.GetLeftSide();
	bool leftPassedRight = a.GetLeftSide() <= b.GetRightSide();
	bool topPassedBottom = a.GetTopSide() <= b.GetBottomSide();
	bool bottomPassedTop = a.GetBottomSide() >= b.GetTopSide();
	return rightPassedLeft && leftPassedRight && topPassedBottom && bottomPassedTop;
}

bool ColliderLibrary::CircleRectangle(Rect rect, vec2 circleCentre, float circleRadius)
{
	vec2 test = circleCentre;
	if (circleCentre.x < rect.GetLeftSide()) test.x = rect.GetLeftSide();
	else if (circleCentre.x > rect.GetRightSide()) test.x = rect.GetRightSide();
	if (circleCentre.y < rect.GetTopSide()) test.y = rect.GetTopSide();
	else if (circleCentre.y > rect.GetBottomSide()) test.y = rect.GetBottomSide();

	vec2 delta = circleCentre - test;
	float distance = delta.length();
	return distance <= circleRadius;
}