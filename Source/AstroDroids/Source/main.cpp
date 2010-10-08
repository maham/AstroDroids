#include "Precompiled.h"

#include "AstroDroidsApplication.h"


/**
 *	Program entry point.
 */
int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int ) {
	AstroDroids::Application *game = new AstroDroids::Application();
	
	MSG message;

	for( ;; ) {
		// check for messages
		if ( PeekMessage( &message, NULL, 0, 0, PM_REMOVE ) )  {
			// handle or dispatch messages
			if ( message.message == WM_QUIT ) {
				break;
			}

			TranslateMessage( &message );
			DispatchMessage( &message );
		} else {
			if( game->update() == false ) {
				break;
			}
		}
	}

	return 0;
}
