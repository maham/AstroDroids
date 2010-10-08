#pragma once


// Forward declarations
//
struct SDL_Surface;


namespace View
{
	class Screen
	{
	public:		Screen( const int aWidth, const int aHeight, const int aBPP, const bool aWindowedFlag );
				~Screen();
				
	private:	SDL_Surface *mySurface;
	};
}
