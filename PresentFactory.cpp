#include "PresentFactory.h"

PresentFactory::PresentFactory(const IPlacementGenerator& placementGenerator, CollisionHandler* collisionHandler, ScoreTracker& scoreTracker) :
	placementGenerator(placementGenerator),
	presents(new std::vector<Present*>),
	collisionHandler(collisionHandler),
	scoreTracker(scoreTracker)
{
}

PresentFactory::~PresentFactory()
{
	for (int i = 0; i < presents->size(); ++i)
	{
		collisionHandler->Deregister((*presents)[i]->GetCollider());
		delete (*presents)[i];
	}
	delete presents;
}

void PresentFactory::Draw(Surface* screen)
{
	for (int i = 0; i < presents->size(); ++i)
	{
		(*presents)[i]->Draw(screen);
	}
}

void PresentFactory::GeneratePresent()
{
	int presentNumber = rand() % 3;
	Present* present = new Present((presentNumber + 1) * 100, presentNumber, placementGenerator.GetPlacement(), *this);
	collisionHandler->Register(present->GetCollider());
	presents->push_back(present);
}

void PresentFactory::NotifyPresentCollision(Present& present, ColliderType colliderType)
{
	std::vector<Present*>::iterator result = std::find(presents->begin(), presents->end(), &present);

	if (result == presents->end())
		return;

	presents->erase(result);
	collisionHandler->Deregister(present.GetCollider());
	scoreTracker.IncrementScore(present.GetPointsToReward());
	delete &present;

	GeneratePresent();
}
