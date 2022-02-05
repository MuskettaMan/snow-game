#pragma once
#include <vector>

#include "IDrawable.h"
#include "IUpdatable.h"
#include "Snowflake.h"

using namespace Tmpl8;

class SnowstormManager : public IDrawable, public IUpdatable
{
public:
	SnowstormManager();
	~SnowstormManager();
	void Draw(Surface* screen) override;
	void Update() override;
	const vec2 GRAVITY = vec2(0, 0.5f);

private:
	std::vector<Snowflake*>* snowflakes;
	float lastSpawnTime;
	float interval;
};

