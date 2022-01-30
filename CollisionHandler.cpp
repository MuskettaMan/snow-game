#include "CollisionHandler.h"

CollisionHandler::CollisionHandler() : colliders(new std::vector<Collider*>())
{
}

CollisionHandler::~CollisionHandler()
{
	colliders->clear();
	delete colliders;
}

void CollisionHandler::Update()
{
	for (int i = 0; i < colliders->size(); ++i)
	{
		for (int j = 0; j < colliders->size(); ++j)
		{
			// If colliders are the same (same address) than we skip.
			if(&colliders->at(i) == &colliders->at(j))
				continue;

			colliders->at(i)->Collides(*colliders->at(j));
		}
	}
}

void CollisionHandler::Register(Collider* collider) const
{
	colliders->push_back(collider);
}

void CollisionHandler::Deregister(Collider* collider)
{
	std::vector<Collider*>::iterator result = std::find(colliders->begin(), colliders->end(), collider);
	if(result != colliders->end())
		colliders->erase(result);
}
