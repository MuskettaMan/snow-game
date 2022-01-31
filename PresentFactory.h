#pragma once
#include <vector>
#include <random>

#include "IPlacementGenerator.h"
#include "Present.h"
#include "CollisionHandler.h"
#include "ScoreTracker.h"

using namespace Tmpl8;

class PresentFactory : public IDrawable, public IPresentCollisionNotifier
{
public:
	PresentFactory(const IPlacementGenerator& placementGenerator, CollisionHandler* collisionHandler, ScoreTracker& scoreTracker);
	~PresentFactory();
	void Draw(Surface* screen) override;
	void GeneratePresent();
	void NotifyPresentCollision(Present& present, ColliderType colliderType) override;

private:
	const IPlacementGenerator& placementGenerator;
	std::vector<Present*>* presents;
	CollisionHandler* collisionHandler;
	ScoreTracker& scoreTracker;
};
