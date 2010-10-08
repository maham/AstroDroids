#pragma once


#include <map>
#include <list>
#include "UtilitiesIEventManager.h"


namespace Utilities {
	class EventManager : public IEventManager {
	public:		typedef std::list< IEventListenerSPtr > EventListenerList;
				typedef std::map< unsigned long, EventListenerList > EventListenerMap;
				typedef std::pair< unsigned long, EventListenerList > EventListenerMapEntry;
				
				EventManager( void );
				~EventManager( void );
				
				void AddEventListener( const IEventListenerSPtr &aListener, const EventType &aType );
				void RemoveEventListener( const IEventListenerSPtr &aListener, const EventType &aType );
				//void QueueEvent( const IEventData &anEvent );
				bool TriggerEvent( const IEventSPtr &anEvent ) const;
				
	private:	EventListenerMap _eventListenerRegistry;
	};

	typedef boost::shared_ptr< EventManager > EventManagerSPtr;
}
