#pragma once
#include "Character.h"
class ImpCharacter : public Character
{
public:
	ImpCharacter(vec2 position, float speed);
	~ImpCharacter();
	void Draw(Surface* screen) override;
private:
	int frameCounter;
};

