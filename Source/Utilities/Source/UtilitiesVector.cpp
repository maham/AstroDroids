#include "UtilitiesVector.h"
#include <cmath>


const Utilities::Vector2 Utilities::Vector2::Zero( 0.0f, 0.0f );
const Utilities::Vector2 Utilities::Vector2::UnitX( 1.0f, 0.0f );
const Utilities::Vector2 Utilities::Vector2::UnitY( 0.0f, 1.0f );
const Utilities::Vector2 Utilities::Vector2::One( 1.0f, 1.0f );

const Utilities::Vector3 Utilities::Vector3::Zero( 0.0f, 0.0f, 0.0f );
const Utilities::Vector3 Utilities::Vector3::UnitX( 1.0f, 0.0f, 0.0f );
const Utilities::Vector3 Utilities::Vector3::UnitY( 0.0f, 1.0f, 0.0f );
const Utilities::Vector3 Utilities::Vector3::UnitZ( 0.0f, 0.0f, 1.0f );
const Utilities::Vector3 Utilities::Vector3::One( 1.0f, 1.0f, 1.0f );


// Constructors/Destructors
//


Utilities::Vector2::Vector2( void )
: x( _components[0] )
, y( _components[1] )
{
	_components[0]
	= _components[1]
	= 0;
}


Utilities::Vector2::Vector2( const Vector2 &aVector )
: x( _components[0] )
, y( _components[1] )
{
	x = aVector.x;
	y = aVector.y;
}


Utilities::Vector2::Vector2( const float anX, const float anY )
: x( _components[0] )
, y( _components[1] )
{
	x = anX;
	y = anY;
}


// Operator overloads
//


Utilities::Vector2 Utilities::Vector2::operator +( const Vector2 &aVector ) const
{
	Vector2 returnVector;

	returnVector.x = x + aVector.x;
	returnVector.y = y + aVector.y;

	return returnVector;
}


Utilities::Vector2 Utilities::Vector2::operator -( const Vector2 &aVector ) const
{
	Vector2 returnVector;

	returnVector.x = x - aVector.x;
	returnVector.y = y - aVector.y;

	return returnVector;
}


Utilities::Vector2 Utilities::Vector2::operator *( const float aMagnitude ) const
{
	return Vector2( x * aMagnitude, y * aMagnitude );
}


Utilities::Vector2 Utilities::Vector2::operator -( void ) const
{
	return Vector2( -x, -y );
}


Utilities::Vector2 Utilities::Vector2::operator /( const float aDivisor ) const
{
	return Vector2( x / aDivisor, y / aDivisor );
}


bool Utilities::Vector2::operator ==( const Vector2 &aVector ) const
{
	return ( x == aVector.x && y == aVector.y );
}


bool Utilities::Vector2::operator !=( const Vector2 &aVector ) const
{
	return ( x != aVector.x || y != aVector.y );
}


Utilities::Vector2 &Utilities::Vector2::operator =( const Vector2 &aVector )
{
	if( this != &aVector )
	{
		x = aVector.x;
		y = aVector.y;
	}

	return *this;
}


Utilities::Vector2 &Utilities::Vector2::operator +=( const Vector2 &aVector )
{
	x += aVector.x;
	y += aVector.y;

	return *this;
}


Utilities::Vector2 &Utilities::Vector2::operator -=( const Vector2 &aVector )
{
	x -= aVector.x;
	y -= aVector.y;

	return *this;
}


Utilities::Vector2 &Utilities::Vector2::operator *=( const float aMagnitude )
{
	x *= aMagnitude;
	y *= aMagnitude;

	return *this;
}


Utilities::Vector2 &Utilities::Vector2::operator /=( const float aDivisor )
{
	x /= aDivisor;
	y /= aDivisor;

	return *this;
}


float &Utilities::Vector2::operator []( const unsigned int anIndex )
{
	return _components[anIndex];
}


const float Utilities::Vector2::operator []( const unsigned int anIndex ) const
{
	return _components[anIndex];
}


const float Utilities::Vector2::Length( void ) const
{
	return sqrt( x * x + y * y );
}


const float Utilities::Vector2::SquareLength( void ) const
{
	return x * x + y * y;
}


const float Utilities::Vector2::Angle( void ) const
{
	return atan2( y, x );
}


void Utilities::Vector2::Rotate( const float anAngle )
{
	//float length = Length();

	//x = length * cos( anAngle );
	//y = length * sin( anAngle );
	x = cos( anAngle ) * x - sin( anAngle ) * y;
	y = sin( anAngle ) * x + cos( anAngle ) * y;
}


Utilities::Vector2 Utilities::Vector2::Normal( void ) const
{
	return Vector2( y, x );
}


Utilities::Vector2 Utilities::Vector2::Normalize( void ) const
{
	return Normalize( *this );
}


const float Utilities::Vector2::Manhattan( const Vector2 &aVector ) const
{
	return abs( x - aVector.x ) + abs( y - aVector.y );
}


// Static members
//

const float Utilities::Vector2::Dot( const Vector2 &aFirstVector, const Vector2 &aSecondVector )
{
	return ( aFirstVector.x * aSecondVector.x + aFirstVector.y * aSecondVector.y );
};


Utilities::Vector2 Utilities::Vector2::Normalize( const Vector2 &aVector )
{
	Vector2 normalizedVector( aVector );
	float length = normalizedVector.Length();

	normalizedVector.x /= length;
	normalizedVector.y /= length;

	return normalizedVector;
}





Utilities::Vector3::Vector3( void )
: x( _components[0] )
, y( _components[1] )
, z( _components[2] )
{
	_components[0]
	= _components[1]
	= _components[2]
	= 0;
}


Utilities::Vector3::Vector3( const Vector3 &aVector )
: x( _components[0] )
, y( _components[1] )
, z( _components[2] )
{
	x = aVector.x;
	y = aVector.y;
	z = aVector.z;
}


Utilities::Vector3::Vector3( const float anX, const float anY, const float aZ )
: x( _components[0] )
, y( _components[1] )
, z( _components[2] )
{
	x = anX;
	y = anY;
	z = aZ;
}


// Operator overloads
//


Utilities::Vector3 Utilities::Vector3::operator +( const Vector3 &aVector ) const
{
	Vector3 returnVector;

	returnVector.x = x + aVector.x;
	returnVector.y = y + aVector.y;
	returnVector.z = z + aVector.z;

	return returnVector;
}


Utilities::Vector3 Utilities::Vector3::operator -( const Vector3 &aVector ) const
{
	Vector3 returnVector;

	returnVector.x = x - aVector.x;
	returnVector.y = y - aVector.y;
	returnVector.z = z - aVector.z;

	return returnVector;
}


Utilities::Vector3 Utilities::Vector3::operator *( const float aMagnitude ) const
{
	return Vector3( x * aMagnitude, y * aMagnitude, z * aMagnitude );
}


Utilities::Vector3 Utilities::Vector3::operator -( void ) const
{
	return Vector3( -x, -y, -z );
}


Utilities::Vector3 Utilities::Vector3::operator /( const float aDivisor ) const
{
	return Vector3( x / aDivisor, y / aDivisor, z / aDivisor );
}


bool Utilities::Vector3::operator ==( const Vector3 &aVector ) const
{
	return ( x == aVector.x && y == aVector.y && z == aVector.z );
}


bool Utilities::Vector3::operator !=( const Vector3 &aVector ) const
{
	return ( x != aVector.x || y != aVector.y || z != aVector.z );
}


Utilities::Vector3 &Utilities::Vector3::operator =( const Vector3 &aVector )
{
	if( this != &aVector )
	{
		x = aVector.x;
		y = aVector.y;
		z = aVector.z;
	}

	return *this;
}


Utilities::Vector3 &Utilities::Vector3::operator +=( const Vector3 &aVector )
{
	x += aVector.x;
	y += aVector.y;
	z += aVector.z;

	return *this;
}


Utilities::Vector3 &Utilities::Vector3::operator -=( const Vector3 &aVector )
{
	x -= aVector.x;
	y -= aVector.y;
	z -= aVector.z;

	return *this;
}


Utilities::Vector3 &Utilities::Vector3::operator *=( const float aMagnitude )
{
	x *= aMagnitude;
	y *= aMagnitude;
	z *= aMagnitude;

	return *this;
}


Utilities::Vector3 &Utilities::Vector3::operator /=( const float aDivisor )
{
	x /= aDivisor;
	y /= aDivisor;
	z /= aDivisor;

	return *this;
}


float &Utilities::Vector3::operator []( const unsigned int anIndex )
{
	return _components[anIndex];
}


const float Utilities::Vector3::operator []( const unsigned int anIndex ) const
{
	return _components[anIndex];
}


const float Utilities::Vector3::Length( void ) const
{
	return sqrt( x * x + y * y + z * z );
}


const float Utilities::Vector3::SquareLength( void ) const
{
	return x * x + y * y + z * z;
}


//const float Vector3::Angle( void ) const
//{
//	return atan2( y, x );
//}
//
//
//void Vector3::Rotate( const float anAngle )
//{
//	float length = Length();
//
//	x = length * cos( anAngle );
//	y = length * sin( anAngle );
//}
//
//
//Vector3 Vector3::Normal( void ) const
//{
//	return Vector3( y, x );
//}


Utilities::Vector3 &Utilities::Vector3::normalize( void )
{
	*this = Normalize( *this );
	return *this;
}


const float Utilities::Vector3::Manhattan( const Vector3 &aVector ) const
{
	return abs( x - aVector.x ) + abs( y - aVector.y ) + abs( z - aVector.z );
}


// Static members
//

const float Utilities::Vector3::Dot( const Vector3 &aFirstVector, const Vector3 &aSecondVector ) {
	return ( aFirstVector.x * aSecondVector.x + aFirstVector.y * aSecondVector.y + aFirstVector.z * aSecondVector.z );
};


const Utilities::Vector3 Utilities::Vector3::Cross( const Vector3 &aFirstVector, const Vector3 &aSecondVector ) {
    Vector3 crossProduct;

    crossProduct.x = aFirstVector.y * aSecondVector.z - aFirstVector.z * aSecondVector.y;
    crossProduct.y = aFirstVector.z * aSecondVector.x - aFirstVector.x * aSecondVector.z;
    crossProduct.z = aFirstVector.x * aSecondVector.y - aFirstVector.y * aSecondVector.x;

    return crossProduct;
}


Utilities::Vector3 Utilities::Vector3::Normalize( const Vector3 &aVector )
{
	Vector3 normalizedVector( aVector );
	float length = normalizedVector.Length();

	normalizedVector.x /= length;
	normalizedVector.y /= length;
	normalizedVector.z /= length;

	return normalizedVector;
}
