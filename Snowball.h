#pragma once
#include "surface.h"
#include "template.h"
#include "IUpdatable.h"
#include "Collider.h"
#include "Rect.h"

using namespace Tmpl8;

class Snowball : public IUpdatable
{
public:
	Snowball(vec2 origin, vec2 direction);
	~Snowball();
	void Update() override;
	void Draw(Surface* screen) const;
	float GetStartTime();
	const Collider& GetCollider() const;

private:
	Collider* collider;
	Rect* rect;
	vec2 position;
	vec2 velocity;
	Sprite* sprite;
	float startTime;
};

