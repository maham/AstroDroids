#pragma once


#include "UtilitiesVector.h"
#include <cstring>


namespace Utilities {
	class Matrix4 {
	public:		static const unsigned int NumComponents = 16;
				typedef float Components[NumComponents];
				
				Matrix4( void );
				Matrix4(
					const float  a0, const float  a1, const float  a2, const float  a3,
					const float  a4, const float  a5, const float  a6, const float  a7,
					const float  a8, const float  a9, const float a10, const float a11,
					const float a12, const float a13, const float a14, const float a15 );
				Matrix4( const Matrix4 &aSourceMatrix );
				
				inline Utilities::Vector3 translation( void ) const {
					return Vector3( components[12], components[13], components[14] );
				}
				
				inline Utilities::Vector3 up( void ) const {
					return Vector3( components[0], components[1], components[2] );
				}
				
				inline Utilities::Vector3 right( void ) const {
					return Vector3( components[4], components[5], components[6] );
				}
				
				inline Utilities::Vector3 forward( void ) const {
					return Vector3( components[8], components[9], components[10] );
				}
				
				void transformVector( Vector3 &aVector ) const;

				Matrix4 operator *( const Matrix4 &aCoefficient ) const;
				Matrix4 &operator *=( const Matrix4 &aCoefficient );
				bool operator ==( const Matrix4 &aComparator ) const;
				
				inline bool operator !=( const Matrix4 &aComparator ) const {
					return !( *this == aComparator );
				}

				inline Matrix4 &operator =( const Matrix4 &aSourceMatrix ) {
					memcpy( &components, &aSourceMatrix.components, sizeof( float ) * NumComponents );
					return *this;
				}
				
				inline float &operator []( const unsigned int anIndex ) {
					return components[anIndex];
				}
				
				inline float operator []( const unsigned int anIndex ) const
				{
					return components[anIndex];
				}
				
				Components components;

				static Matrix4 Rotation( const float &anAngle, const Utilities::Vector3 &anAxis );
				static Matrix4 RotationX( const float anAngle );
				static Matrix4 RotationY( const float anAngle );
				static Matrix4 RotationZ( const float anAngle );
				static Matrix4 Translation( const Vector3 &aTranslation );
				static Matrix4 Transpose( const Matrix4 &aSourceMatrix );
				
				static const Matrix4 Identity;
				static const Matrix4 Invert;
				static const Matrix4 InvertX;
				static const Matrix4 InvertY;
				static const Matrix4 InvertZ;
				static const Matrix4 InvertXY;
				static const Matrix4 InvertXZ;
				static const Matrix4 InvertYZ;
				static const Matrix4 InvertXYZ;
	};
}
