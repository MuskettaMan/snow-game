#include "Snowflake.h"
#include <algorithm>
#include "Game.h"

Snowflake::Snowflake() : position({static_cast<float>(rand() % ScreenWidth), 0}), velocity({0, static_cast<float>(rand() % 3 + 6)}), acceleration({0, 0}), radius(rand() % 8 + 2), reachedBottom(false), mass(1)
{
	position.y = -radius;
}

void Snowflake::Draw(Surface* screen)
{
	vec2 topLeft(static_cast<int>(position.x) % ScreenWidth, ClampScreenSpace(position.y, static_cast<float>(ScreenHeight)));
	

	vec2 bottomRight(static_cast<int>(topLeft.x + radius) % ScreenWidth, ClampScreenSpace(position.y + radius, static_cast<float>(ScreenHeight)));

	screen->Bar(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y, 0xffffff);
}

void Snowflake::Update()
{
	velocity += acceleration;

	float limit = radius * 10;
	if(velocity.sqrLentgh() > limit * limit)
	{
		velocity = velocity.normalized();
		velocity *= limit;
	}

	position += velocity * (Game::GetDeltaTime() / 1000);

	position.x += sin(Game::GetTime() / 10000) * InvLerp(2, 10, radius) / 2 + 0.5f;

	acceleration *= 0;

	if (position.y > ScreenHeight - radius)
	{
		reachedBottom = true;
	}
}

bool Snowflake::GetReachedBottom() const
{
	return reachedBottom;
}

void Snowflake::ApplyForce(vec2 force)
{
	//force *= radius;

	acceleration += force;
}

float Snowflake::ClampScreenSpace(float value, float max)
{
	return std::max(0.0f, std::min(value, max));
}

float Snowflake::InvLerp(float a, float b, float v)
{
	return (v - a) / (b - a);
}
