#pragma once
#include "IDrawable.h"
#include "template.h"
#include <random>

#include "IUpdatable.h"

using namespace Tmpl8;

class Snowflake : public IDrawable, public IUpdatable
{
public:
	Snowflake();
	void Draw(Surface* screen) override;
	void Update() override;
	bool GetReachedBottom() const;
	void ApplyForce(vec2 force);

private:
	vec2 position;
	vec2 velocity;
	vec2 acceleration;
	float mass;
	int radius;
	bool reachedBottom;
};

