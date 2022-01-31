#pragma once
#include "IDrawable.h"
#include "ScoreTracker.h"

using namespace Tmpl8;

class ScoreDisplay : public IDrawable
{
public:
	ScoreDisplay(const ScoreTracker& scoreTracker);
	void Draw(Surface* screen) override;

private:
	const ScoreTracker& scoreTracker;
};

