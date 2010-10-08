#include "Precompiled.h"

#include "AstroDroidsApplication.h"
#include <ModelEvents.h>
#include <ViewIManager.h>


AstroDroids::Application::Application( void ) {
	_viewManager = View::IManager::Create( "viewSettings.xml" );
	
	QueryPerformanceFrequency( (LARGE_INTEGER *)&_frequency );
	QueryPerformanceCounter( (LARGE_INTEGER *)&_lastCounter );
}


bool AstroDroids::Application::update( void ) {
	__int64 currentCounter;
	QueryPerformanceCounter( (LARGE_INTEGER *)&currentCounter );
	float deltaTime = static_cast< float >( currentCounter - _lastCounter ) / static_cast< float >( _frequency );
	_lastCounter = currentCounter;

	return _viewManager->update( deltaTime );
}
