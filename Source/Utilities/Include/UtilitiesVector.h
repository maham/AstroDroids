#ifndef _COMMON_VECTOR_H_
#define _COMMON_VECTOR_H_


namespace Utilities
{
	typedef class Vector2
	{
	public:		Vector2( void );
				Vector2( const Vector2 &aVector2 );
				Vector2( const float anX, const float anY );

				Vector2 operator +( const Vector2 &aVector ) const;
				Vector2 operator -( const Vector2 &aVector ) const;
				Vector2 operator *( const float aCoefficient ) const;
				Vector2 operator /( const float aDivisor ) const;
				Vector2 operator -( void ) const;
				bool operator ==( const Vector2 &aVector ) const;
				bool operator !=( const Vector2 &aVector ) const;
				Vector2 &operator =( const Vector2 &aVector );
				Vector2 &operator +=( const Vector2 &aVector );
				Vector2 &operator -=( const Vector2 &aVector );
				Vector2 &operator *=( const float aCoefficient );
				Vector2 &operator /=( const float aDivisor );
				float &operator []( const unsigned int anIndex );
				const float operator []( const unsigned int anIndex ) const;

				const float Length( void ) const;
				const float SquareLength( void ) const;
				const float Angle( void ) const;
				void Rotate( const float anAngle );
				Vector2 Normal( void ) const;
				Vector2 Normalize( void ) const;
				const float Manhattan( const Vector2 &aVector ) const;

				float	&x,
						&y;

				static const float Dot( const Vector2 &aFirstVector, const Vector2 &aSecondVector );
				static Vector2 Normalize( const Vector2 &aVector );

				static const Vector2	Zero,
										UnitX,
										UnitY,
										One;

	private:	float _components[2];
	} *Vector2Ptr, *const Vector2CPtr;
	
	
	typedef class Vector3
	{
	public:		Vector3( void );
				Vector3( const Vector3 &aVector3 );
				Vector3( const float anX, const float anY, const float aZ );

				Vector3 operator +( const Vector3 &aVector ) const;
				Vector3 operator -( const Vector3 &aVector ) const;
				Vector3 operator *( const float aCoefficient ) const;
				Vector3 operator /( const float aDivisor ) const;
				Vector3 operator -( void ) const;
				bool operator ==( const Vector3 &aVector ) const;
				bool operator !=( const Vector3 &aVector ) const;
				Vector3 &operator =( const Vector3 &aVector );
				Vector3 &operator +=( const Vector3 &aVector );
				Vector3 &operator -=( const Vector3 &aVector );
				Vector3 &operator *=( const float aCoefficient );
				Vector3 &operator /=( const float aDivisor );
				float &operator []( const unsigned int anIndex );
				const float operator []( const unsigned int anIndex ) const;

				const float Length( void ) const;
				const float SquareLength( void ) const;
				//const float Angle( void ) const;
				//void Rotate( const float anAngle );
				//Vector3 Normal( void ) const;
				Vector3 &normalize( void );
				const float Manhattan( const Vector3 &aVector ) const;

				float	&x,
						&y,
						&z;

				static const float Dot( const Vector3 &aFirstVector, const Vector3 &aSecondVector );
				static const Vector3 Cross( const Vector3 &aFirstVector, const Vector3 &aSecondVector );
				static Vector3 Normalize( const Vector3 &aVector );

				static const Vector3	Zero,
										UnitX,
										UnitY,
										UnitZ,
										One;

	private:	float _components[3];
	} *Vector3Ptr, *const Vector3CPtr;

	
	typedef class Vector2 Point2, *Point2Ptr, *const Point2CPtr;
	typedef class Vector3 Point3, *Point3Ptr, *const Point3CPtr;
}

#endif // _COMMON_VECTOR_H_
