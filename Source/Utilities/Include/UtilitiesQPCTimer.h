#pragma once


#include <list>
#include "UtilitiesITimer.h"


namespace Utilities {
	class QPCTimer {
	public:		QPCTimer( void );
				~QPCTimer( void );
				
				// ITimer interface
				//
				void OnUpdate( void );
				void AttachTimer( const ITimerSPtr &aTimer );
				void DetatchTimer( const ITimerSPtr &aTimer );
				
				inline float GetDeltaT( void ) const {
					return _deltaT;
				}

				inline __int64 GetCounter( void ) const {
					return _lastCounter;
				}

	private:	__int64		_frequency,
							_lastCounter;
				ITimerList	_subTimers;
				float		_deltaT;
	};
}
