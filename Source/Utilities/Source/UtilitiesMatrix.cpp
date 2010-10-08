#include "UtilitiesMatrix.h"
#include <cmath>


#define DEGTORAD(degree) ((degree) * (3.141592654f / 180.0f))
#define RADTODEG(radian) ((radian) * (180.0f / 3.141592654f))


const Utilities::Matrix4 Utilities::Matrix4::Identity(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f );


const Utilities::Matrix4 Utilities::Matrix4::Invert(
	-1.0f,  0.0f,  0.0f,  0.0f,
	 0.0f, -1.0f,  0.0f,  0.0f,
	 0.0f,  0.0f, -1.0f,  0.0f,
	 0.0f,  0.0f,  0.0f,  1.0f );


const Utilities::Matrix4 Utilities::Matrix4::InvertX(
	-1.0f,  0.0f,  0.0f,  0.0f,
	 0.0f,  1.0f,  0.0f,  0.0f,
	 0.0f,  0.0f,  1.0f,  0.0f,
	 0.0f,  0.0f,  0.0f,  1.0f );


const Utilities::Matrix4 Utilities::Matrix4::InvertY(
	 1.0f,  0.0f,  0.0f,  0.0f,
	 0.0f, -1.0f,  0.0f,  0.0f,
	 0.0f,  0.0f,  1.0f,  0.0f,
	 0.0f,  0.0f,  0.0f,  1.0f );


const Utilities::Matrix4 Utilities::Matrix4::InvertZ(
	 1.0f,  0.0f,  0.0f,  0.0f,
	 0.0f,  1.0f,  0.0f,  0.0f,
	 0.0f,  0.0f, -1.0f,  0.0f,
	 0.0f,  0.0f,  0.0f,  1.0f );


const Utilities::Matrix4 Utilities::Matrix4::InvertXY(
	-1.0f,  0.0f,  0.0f,  0.0f,
	 0.0f, -1.0f,  0.0f,  0.0f,
	 0.0f,  0.0f,  1.0f,  0.0f,
	 0.0f,  0.0f,  0.0f,  1.0f );


const Utilities::Matrix4 Utilities::Matrix4::InvertXZ(
	-1.0f,  0.0f,  0.0f,  0.0f,
	 0.0f,  1.0f,  0.0f,  0.0f,
	 0.0f,  0.0f, -1.0f,  0.0f,
	 0.0f,  0.0f,  0.0f,  1.0f );


const Utilities::Matrix4 Utilities::Matrix4::InvertYZ(
	 1.0f,  0.0f,  0.0f,  0.0f,
	 0.0f, -1.0f,  0.0f,  0.0f,
	 0.0f,  0.0f, -1.0f,  0.0f,
	 0.0f,  0.0f,  0.0f,  1.0f );


const Utilities::Matrix4 Utilities::Matrix4::InvertXYZ(
	-1.0f,  0.0f,  0.0f,  0.0f,
	 0.0f, -1.0f,  0.0f,  0.0f,
	 0.0f,  0.0f, -1.0f,  0.0f,
	 0.0f,  0.0f,  0.0f,  1.0f );


Utilities::Matrix4::Matrix4( void )
{
}

Utilities::Matrix4::Matrix4(
	const float  a0, const float  a1, const float  a2, const float  a3,
	const float  a4, const float  a5, const float  a6, const float  a7,
	const float  a8, const float  a9, const float a10, const float a11,
	const float a12, const float a13, const float a14, const float a15 )
{
	components[ 0] =  a0;
	components[ 1] =  a1;
	components[ 2] =  a2;
	components[ 3] =  a3;

	components[ 4] =  a4;
	components[ 5] =  a5;
	components[ 6] =  a6;
	components[ 7] =  a7;

	components[ 8] =  a8;
	components[ 9] =  a9;
	components[10] = a10;
	components[11] = a11;

	components[12] = a12;
	components[13] = a13;
	components[14] = a14;
	components[15] = a15;
}

Utilities::Matrix4::Matrix4( const Matrix4 &aSourceMatrix )
{
	memcpy( &components, &aSourceMatrix.components, sizeof( float ) * NumComponents );
}


void Utilities::Matrix4::transformVector( Vector3 &aVector ) const {
    float x = aVector.x;
    float y = aVector.y;
    float z = aVector.z;

    aVector.x =	x * components[0] +
				y * components[4] +
				z * components[8];

    aVector.y = x * components[1] +
				y * components[5] +
				z * components[9];

    aVector.z = x * components[2] +
				y * components[6] +
				z * components[10];
}


Utilities::Matrix4 Utilities::Matrix4::operator *( const Matrix4 &aCoeffecient ) const {
    Matrix4 product;
	
    product.components[0]  = ( components[0] * aCoeffecient.components[ 0] ) + ( components[4] * aCoeffecient.components [ 1] ) + ( components [ 8] * aCoeffecient.components[ 2] ) + ( components[12] * aCoeffecient.components[ 3] );
    product.components[1]  = ( components[1] * aCoeffecient.components[ 0] ) + ( components[5] * aCoeffecient.components [ 1] ) + ( components [ 9] * aCoeffecient.components[ 2] ) + ( components[13] * aCoeffecient.components[ 3] );
    product.components[2]  = ( components[2] * aCoeffecient.components[ 0] ) + ( components[6] * aCoeffecient.components [ 1] ) + ( components [10] * aCoeffecient.components[ 2] ) + ( components[14] * aCoeffecient.components[ 3] );
    product.components[3]  = ( components[3] * aCoeffecient.components[ 0] ) + ( components[7] * aCoeffecient.components [ 1] ) + ( components [11] * aCoeffecient.components[ 2] ) + ( components[15] * aCoeffecient.components[ 3] );
	
	product.components[4]  = ( components[0] * aCoeffecient.components[ 4] ) + ( components[4] * aCoeffecient.components [ 5] ) + ( components [ 8] * aCoeffecient.components[ 6] ) + ( components[12] * aCoeffecient.components[ 7] );
    product.components[5]  = ( components[1] * aCoeffecient.components[ 4] ) + ( components[5] * aCoeffecient.components [ 5] ) + ( components [ 9] * aCoeffecient.components[ 6] ) + ( components[13] * aCoeffecient.components[ 7] );
    product.components[6]  = ( components[2] * aCoeffecient.components[ 4] ) + ( components[6] * aCoeffecient.components [ 5] ) + ( components [10] * aCoeffecient.components[ 6] ) + ( components[14] * aCoeffecient.components[ 7] );
    product.components[7]  = ( components[3] * aCoeffecient.components[ 4] ) + ( components[7] * aCoeffecient.components [ 5] ) + ( components [11] * aCoeffecient.components[ 6] ) + ( components[15] * aCoeffecient.components[ 7] );
	
	product.components[8]  = ( components[0] * aCoeffecient.components[ 8] ) + ( components[4] * aCoeffecient.components [ 9] ) + ( components [ 8] * aCoeffecient.components[10] ) + ( components[12] * aCoeffecient.components[11] );
    product.components[9]  = ( components[1] * aCoeffecient.components[ 8] ) + ( components[5] * aCoeffecient.components [ 9] ) + ( components [ 9] * aCoeffecient.components[10] ) + ( components[13] * aCoeffecient.components[11] );
    product.components[10] = ( components[2] * aCoeffecient.components[ 8] ) + ( components[6] * aCoeffecient.components [ 9] ) + ( components [10] * aCoeffecient.components[10] ) + ( components[14] * aCoeffecient.components[11] );
    product.components[11] = ( components[3] * aCoeffecient.components[ 8] ) + ( components[7] * aCoeffecient.components [ 9] ) + ( components [11] * aCoeffecient.components[10] ) + ( components[15] * aCoeffecient.components[11] );
	
	product.components[12] = ( components[0] * aCoeffecient.components[12] ) + ( components[4] * aCoeffecient.components [13] ) + ( components [ 8] * aCoeffecient.components[14] ) + ( components[12] * aCoeffecient.components[15] );
    product.components[13] = ( components[1] * aCoeffecient.components[12] ) + ( components[5] * aCoeffecient.components [13] ) + ( components [ 9] * aCoeffecient.components[14] ) + ( components[13] * aCoeffecient.components[15] );
    product.components[14] = ( components[2] * aCoeffecient.components[12] ) + ( components[6] * aCoeffecient.components [13] ) + ( components [10] * aCoeffecient.components[14] ) + ( components[14] * aCoeffecient.components[15] );
    product.components[15] = ( components[3] * aCoeffecient.components[12] ) + ( components[7] * aCoeffecient.components [13] ) + ( components [11] * aCoeffecient.components[14] ) + ( components[15] * aCoeffecient.components[15] );

    return product;
}


Utilities::Matrix4 &Utilities::Matrix4::operator *=( const Matrix4 &aCoefficient ) {
	*this = *this * aCoefficient;
	return *this;
}


bool Utilities::Matrix4::operator ==( const Matrix4 &aComparator ) const {
	for( int currentComponentIndex = 0; currentComponentIndex < 16; currentComponentIndex++ ) {
		if( components[currentComponentIndex] != aComparator.components[currentComponentIndex] )
			return false;
	}
	
	return true;
}


Utilities::Matrix4 Utilities::Matrix4::Rotation( const float &anAngle, const Vector3 &anAxis ) {
	Matrix4 rotation( Utilities::Matrix4::Identity );
    float s = sin( DEGTORAD( anAngle ) );
    float c = cos( DEGTORAD( anAngle ) );
	
	Utilities::Vector3 axis( Vector3::Normalize( anAxis ) );
	
    float ux = axis.x;
    float uy = axis.y;
    float uz = axis.z;
    
    rotation.components[0]  = c + (1-c) * ux;
    rotation.components[1]  = (1-c) * ux*uy + s*uz;
    rotation.components[2]  = (1-c) * ux*uz - s*uy;
    
    rotation.components[4]  = (1-c) * uy*ux - s*uz;
    rotation.components[5]  = c + (1-c) * pow(uy,2);
    rotation.components[6]  = (1-c) * uy*uz + s*ux;
    
    rotation.components[8]  = (1-c) * uz*ux + s*uy;
    rotation.components[9]  = (1-c) * uz*uz - s*ux;
    rotation.components[10] = c + (1-c) * pow(uz,2);
	
	return rotation;
}


Utilities::Matrix4 Utilities::Matrix4::RotationX( const float anAngle ) {
	Matrix4 rotation( Utilities::Matrix4::Identity );
	
    float s = sin( DEGTORAD( anAngle ) );
    float c = cos( DEGTORAD( anAngle ) );
	
    rotation.components[5]  =  c;
    rotation.components[6]  =  s;
    rotation.components[9]  = -s;
    rotation.components[10] =  c;
	
	return rotation;
}


Utilities::Matrix4 Utilities::Matrix4::RotationY( const float anAngle ) {
	Matrix4 rotation( Utilities::Matrix4::Identity );
    float s = sin( DEGTORAD( anAngle ) );
    float c = cos( DEGTORAD( anAngle ) );

    rotation.components[0]  =  c;
    rotation.components[2]  = -s;
    rotation.components[8]  =  s;
    rotation.components[10] =  c;
	
	return rotation;
}


Utilities::Matrix4 Utilities::Matrix4::RotationZ( const float anAngle ) {
	Matrix4 rotation( Utilities::Matrix4::Identity );
    float s = sin( DEGTORAD( anAngle ) );
    float c = cos( DEGTORAD( anAngle ) );

    rotation.components[0]  =  c;
    rotation.components[1]  =  s;
    rotation.components[4]  = -s;
    rotation.components[5]  =  c;
	
	return rotation;
}


Utilities::Matrix4 Utilities::Matrix4::Translation( const Vector3 &aTranslation ) {
	Matrix4 translation( Utilities::Matrix4::Identity );
	
	translation[12] = aTranslation.x;
	translation[13] = aTranslation.y;
	translation[14] = aTranslation.z;
	
	return translation;
}


Utilities::Matrix4 Utilities::Matrix4::Transpose( const Utilities::Matrix4 &aSourceMatrix ) {
    Matrix4 transposed;

    transposed.components[0]  = aSourceMatrix.components[0];
    transposed.components[1]  = aSourceMatrix.components[4];
    transposed.components[2]  = aSourceMatrix.components[8];
    transposed.components[3]  = aSourceMatrix.components[12];

    transposed.components[4]  = aSourceMatrix.components[1];
    transposed.components[5]  = aSourceMatrix.components[5];
    transposed.components[6]  = aSourceMatrix.components[9];
    transposed.components[7]  = aSourceMatrix.components[13];

    transposed.components[8]  = aSourceMatrix.components[2];
    transposed.components[9]  = aSourceMatrix.components[6];
    transposed.components[10] = aSourceMatrix.components[10];
    transposed.components[11] = aSourceMatrix.components[14];

    transposed.components[12] = aSourceMatrix.components[3];
    transposed.components[13] = aSourceMatrix.components[7];
    transposed.components[14] = aSourceMatrix.components[11];
    transposed.components[15] = aSourceMatrix.components[15];

    return transposed;
}
