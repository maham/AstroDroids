#pragma once


#include "UtilitiesHashedString.h"
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <sstream>


namespace Utilities {
	typedef HashedString EventType;
	
	class IEvent {
	public:		virtual const EventType &GetEventType( void ) const = 0;
				virtual float GetTimeStamp( void ) const = 0;
	};
	
	
	typedef boost::shared_ptr< IEvent > IEventSPtr;
	
	
	class BaseEvent : public IEvent, public boost::noncopyable {
	public:		explicit BaseEvent( const float aTimeStamp = 0.0f )
				: _timeStamp( aTimeStamp )
				{}
				
				virtual ~BaseEvent( void ) {}
				virtual const EventType &GetEventType( void ) const = 0;
				
				float GetTimeStamp( void ) const {
					return _timeStamp;
				}
				
	protected:	const float _timeStamp;
	};
}
