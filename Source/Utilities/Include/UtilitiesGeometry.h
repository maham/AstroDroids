#pragma once


#include "UtilitiesVector.h"


namespace Utilities
{
	struct Sphere
	{
		Point2	center;
		float	radius;
	};


	struct Transformation
	{
		Point2	position;
		Vector2	orientation;

		Transformation( const Point2 &aPosition, const Vector2 &anOrientation ) {
			position = aPosition;
			orientation = anOrientation;
		}
	};
}
