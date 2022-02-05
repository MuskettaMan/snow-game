#include "Snowflake.h"

#include "Game.h"

Snowflake::Snowflake() : position({static_cast<float>(rand() % ScreenWidth), 0}), velocity({0, static_cast<float>(rand() % 3 + 6)}), acceleration({0, 0}), radius(rand() % 8 + 2), reachedBottom(false), mass(1)
{
}

void Snowflake::Draw(Surface* screen)
{
	screen->Bar(position.x, position.y, position.x + radius, position.y + radius, 0xffffff);
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

	acceleration *= 0;

	if (position.y > ScreenHeight - radius)
	{
		reachedBottom = true;
		position.y = ScreenHeight - radius;
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
