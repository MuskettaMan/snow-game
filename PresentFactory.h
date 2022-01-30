#pragma once
#include <vector>
#include <random>

#include "IPlacementGenerator.h"
#include "Present.h"
#include "CollisionHandler.h"

using namespace Tmpl8;

class PresentFactory : public IDrawable
{
public:
	PresentFactory(const IPlacementGenerator& placementGenerator, CollisionHandler* collisionHandler);
	~PresentFactory();
	void Draw(Surface* screen) override;
	void GeneratePresent() const;

private:
	const IPlacementGenerator& placementGenerator;
	std::vector<Present*>* presents;
	CollisionHandler* collisionHandler;
};

