#include "UtilitiesTimer.h"
#include <boost/shared_ptr.hpp>


Utilities::Timer::Timer( const float aStartTime )
: _currentT( aStartTime )
, _deltaT( 0.0f )
{
}


void Utilities::Timer::OnUpdate( const float aDeltaT ) {
	_deltaT = aDeltaT;
	_currentT += aDeltaT;

	for( ITimerList::iterator currentTimerIterator = _subTimers.begin(); currentTimerIterator != _subTimers.end(); ++currentTimerIterator ) {
		( *currentTimerIterator )->OnUpdate( aDeltaT );
	}
}


void Utilities::Timer::AttachTimer( const ITimerSPtr &aTimer ) {
	_subTimers.push_back( aTimer );
}


void Utilities::Timer::DetatchTimer( const ITimerSPtr &aTimer ) {
	for( ITimerList::iterator currentTimerIterator = _subTimers.begin(); currentTimerIterator != _subTimers.end(); ++currentTimerIterator ) {
		if( *currentTimerIterator == aTimer ) {
			_subTimers.erase( currentTimerIterator );
			break;
		}
	}
}

