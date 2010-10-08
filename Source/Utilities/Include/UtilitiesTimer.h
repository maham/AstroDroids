#pragma once


#include <list>
#include "UtilitiesITimer.h"


namespace Utilities {
	class Timer : public ITimer {
	public:		Timer( const float aStartTime = 0.0f );
				
				// ITimer interface
				//
				void OnUpdate( const float aDeltaT );
				void AttachTimer( const ITimerSPtr &aTimer );
				void DetatchTimer( const ITimerSPtr &aTimer );

	private:	float		_currentT,
							_deltaT;
				ITimerList	_subTimers;
	};
}
