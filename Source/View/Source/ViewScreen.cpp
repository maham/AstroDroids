#include "ViewScreen.h"
#include <SDL.h>


View::Screen::Screen( const int aWidth, const int aHeight, const int aBPP, const bool aWindowedFlag )
{
	unsigned int surfaceSettings = SDL_HWSURFACE || SDL_DOUBLEBUF;

	if( !aWindowedFlag )
		surfaceSettings |= SDL_FULLSCREEN;

	mySurface = SDL_SetVideoMode( aWidth, aHeight, aBPP, surfaceSettings );
}