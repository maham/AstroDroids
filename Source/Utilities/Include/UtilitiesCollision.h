#pragma once

namespace Utilities
{
	struct Sphere;
	typedef class Vector2 Point2;
}


namespace Utilities
{
	enum CollisionPrediction
	{
		NotColliding,
		FutureCollision,
		AlreadyIntersecting,
	};
	
	
	const CollisionPrediction IsColliding( const Sphere &aSphere1, const Vector2 &aSphere1Velocity, const Sphere &aSphere2, const Vector2 &aSphere2Velocity, float &aT );
	void ElasticCollision( const Sphere &aSphere1, Vector2 &aSphere1Velocity, const float aSphere1Mass, const Sphere &aSphere2, Vector2 &aSphere2Velocity, const float aSphere2Mass );
}
