#include "UtilitiesCollision.h"
#include "UtilitiesGeometry.h"
#include "UtilitiesVector.h"
#include <cmath>


const Utilities::CollisionPrediction Utilities::IsColliding( const Sphere &aSphere1, const Vector2 &aSphere1Velocity, const Sphere &aSphere2, const Vector2 &aSphere2Velocity, float &aT )
{
	Vector2	s = aSphere2.center - aSphere1.center,													// Vector between sphere centers
			v = aSphere2Velocity - aSphere1Velocity;												// Relative motion of s1 with respect to stationary s0
	float	totalRadii = aSphere2.radius + aSphere1.radius,											// Sum of sphere radii
			distance = Vector2::Dot( s, s ) - totalRadii * totalRadii;
	
	if( distance < 0.0f )																					// Spheres initially overlapping so exit directly
	{
		aT = 0.0f;

		return AlreadyIntersecting;
	}

	float a = Vector2::Dot( v, v );

	if( a < 0.5f )																					// Spheres not moving relative each other
	{
		return NotColliding;
	}

	float b = Vector2::Dot( v, s );

	if( b >= 0.0f )																					// Spheres not moving towards each other
	{
		return NotColliding;
	}

	float d = b * b - a * distance;
	
	if( d < 0.0f )																					// No real-valued root, spheres do not intersect
	{
		return NotColliding;
	}

	aT = ( -b - std::sqrt( d ) ) / a;

	return FutureCollision;
}


/**
 *	Performs an elastic collision on two movable spheres.
 */
void Utilities::ElasticCollision( const Sphere &aSphere1, Vector2 &aSphere1Velocity, const float aSphere1Mass, const Sphere &aSphere2, Vector2 &aSphere2Velocity, const float aSphere2Mass )
{
	Vector2	x = ( aSphere1.center - aSphere2.center ).Normalize(),
			v1 = aSphere1Velocity;
	float x1 = Vector2::Dot( x, v1 );
	Vector2 v1x = x * x1,
			v1y = v1 - v1x;
	float	m1 = aSphere1Mass,
			m2 = aSphere2Mass;
	x = x * -1;
	Vector2 v2 = aSphere2Velocity;
	float x2 = Vector2::Dot( x, v2 );
	Vector2 v2x = x * x2,
			v2y = v2 - v2x;

	aSphere1Velocity = v1x * ( ( m1 - m2 ) / ( m1 + m2 ) ) + v2x * ( 2 * m2 / ( m1 + m2 ) ) + v1y;
	aSphere2Velocity = v1x * ( 2 * m1 / ( m1 + m2 ) ) + v2x * ( ( m2 - m1 ) / ( m1 + m2 ) ) + v2y;
}
