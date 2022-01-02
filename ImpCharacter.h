#pragma once
#include "Character.h"
class ImpCharacter : public Character
{
public:
	ImpCharacter();
	~ImpCharacter();
	void Draw(Surface* screen) override;
private:
	int frameCounter;
};

