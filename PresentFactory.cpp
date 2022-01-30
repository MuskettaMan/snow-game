#include "PresentFactory.h"

PresentFactory::PresentFactory(const IPlacementGenerator& placementGenerator, CollisionHandler* collisionHandler) : placementGenerator(placementGenerator), presents(new std::vector<Present*>), collisionHandler(collisionHandler)
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

void PresentFactory::GeneratePresent() const
{
	std::vector<vec2> positions(presents->size());
	for (int i = 0; i < presents->size(); ++i)
	{
		positions[i] = (*presents)[i]->GetRect()->position;
	}

	int presentNumber = rand() % 3;
	Present* present = new Present((presentNumber + 1) * 100, presentNumber, placementGenerator.GetPlacement(&positions));
	collisionHandler->Register(present->GetCollider());
	presents->push_back(present);
}
