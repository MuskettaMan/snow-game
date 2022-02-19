#pragma once
#include "template.h"

using namespace Tmpl8;

/**
 * \brief Defines a bounding box.
 */
class Rect
{
public:
	/**
	 * \brief Position of the rectangle.
	 */
	vec2 position;

	/**
	 * \brief Size of the rectangle.
	 */
	vec2 size;

	/**
	 * \brief Creates the rectangle.
	 */
	Rect();

	/**
	 * \brief Creates the rectangle.
	 * \param position The position of the rectangle.
	 * \param size The size of the rectangle.
	 */
	Rect(vec2 position, vec2 size);

	/**
	 * \brief The top-left position of the rectangle.
	 * \return The top-left position of the rectangle.
	 */
	vec2 GetTopLeft() const;

	/**
	 * \brief The top-right position of the rectangle.
	 * \return The top-right position of the rectangle.
	 */
	vec2 GetTopRight() const;

	/**
	 * \brief The bottom-right position of the rectangle.
	 * \return The bottom-right position of the rectangle.
	 */
	vec2 GetBottomRight() const;

	/**
	 * \brief The bottom-left position of the rectangle.
	 * \return The bottom-left position of the rectangle.
	 */
	vec2 GetBottomLeft() const;
};

