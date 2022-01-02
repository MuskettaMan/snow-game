#pragma once
#include "surface.h"
#include "template.h"

class Snowball
{
public:
	Snowball(Tmpl8::vec2 origin, Tmpl8::vec2 direction);
	~Snowball();
	void Update();
	void Draw(Tmpl8::Surface* screen) const;
	float GetStartTime();

private:
	Tmpl8::vec2 position;
	Tmpl8::vec2 velocity;
	Tmpl8::Sprite* sprite;
	float startTime;
};

