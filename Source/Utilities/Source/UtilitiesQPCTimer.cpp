#include "UtilitiesQPCTimer.h"
#include <boost/shared_ptr.hpp>
#include <windows.h>


Utilities::QPCTimer::QPCTimer( void ) {
	QueryPerformanceFrequency( reinterpret_cast< LARGE_INTEGER * >( &_frequency ) );
	QueryPerformanceCounter( reinterpret_cast< LARGE_INTEGER * >( &_lastCounter ) );
}


Utilities::QPCTimer::~QPCTimer( void ) {
	while( !_subTimers.empty() )
		_subTimers.pop_back();
}


void Utilities::QPCTimer::OnUpdate( void ) {
	__int64 currentCounter;
	QueryPerformanceCounter( reinterpret_cast< LARGE_INTEGER * >( &currentCounter ) );
	_deltaT = static_cast< float >( currentCounter - _lastCounter ) / static_cast< float >( _frequency );
	_lastCounter = currentCounter;

	for( ITimerList::iterator currentTimerIterator = _subTimers.begin(); currentTimerIterator != _subTimers.end(); ++currentTimerIterator ) {
		( *currentTimerIterator )->OnUpdate( _deltaT );
	}
}


void Utilities::QPCTimer::AttachTimer( const ITimerSPtr &aTimer ) {
	_subTimers.push_back( aTimer );
}


void Utilities::QPCTimer::DetatchTimer( const ITimerSPtr &aTimer ) {
	for( ITimerList::iterator currentTimerIterator = _subTimers.begin(); currentTimerIterator != _subTimers.end(); ++currentTimerIterator ) {
		if( *currentTimerIterator == aTimer ) {
			_subTimers.erase( currentTimerIterator );
			break;
		}
	}
}

