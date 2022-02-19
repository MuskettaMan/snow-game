#pragma once
#include <vector>
#include <random>

#include "IPlacementGenerator.h"
#include "Present.h"
#include "CollisionHandler.h"
#include "ScoreTracker.h"

using namespace Tmpl8;

/**
 * \brief Creates presents to be placed on the map.
 */
class PresentFactory : public IDrawable, public IPresentCollisionNotifier
{
public:
	/**
	 * \brief Creates a new present factory.
	 * \param placementGenerator The generator for retrieving placements.
	 * \param collisionHandler The handler for checking collisions.
	 * \param scoreTracker The score tracker for adding score to.
	 */
	PresentFactory(const IPlacementGenerator& placementGenerator, CollisionHandler* collisionHandler, ScoreTracker& scoreTracker);

	/**
	 * \brief Destroys the present factory.
	 */
	~PresentFactory();

	/**
	 * \brief Draws all the composed presents to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen) override;

	/**
	 * \brief Generates a present.
	 */
	void GeneratePresent();

	/**
	 * \brief Notifies of a collision with a present.
	 * \param present The present that was collided with.
	 * \param colliderType The type of collision that occurred.
	 */
	void NotifyPresentCollision(Present& present, ColliderType colliderType) override;

private:
	/**
	 * \brief The generator for retrieving placements.
	 */
	const IPlacementGenerator& placementGenerator;

	/**
	 * \brief All the composed presents.
	 */
	std::vector<Present*>* presents;

	/**
	 * \brief The handler for checking collisions.
	 */
	CollisionHandler* collisionHandler;

	/**
	 * \brief The score tracker for adding score to.
	 */
	ScoreTracker& scoreTracker;
};
