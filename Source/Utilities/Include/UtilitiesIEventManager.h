#pragma once


// Forward declarations
//
namespace boost {
	template< typename TYPE >
	class shared_ptr;
}

namespace Utilities {
	typedef class HashedString EventType;

	class IEventListener;
	typedef boost::shared_ptr< IEventListener > IEventListenerSPtr;

	class IEvent;
	typedef boost::shared_ptr< IEvent > IEventSPtr;
}


namespace Utilities {
	class IEventManager {
	public:		virtual void AddEventListener( const IEventListenerSPtr &anEventListener, const EventType &anEventType ) = 0;
				virtual void RemoveEventListener( const IEventListenerSPtr &anEventListener, const EventType &anEventType ) = 0;
				virtual bool TriggerEvent( const IEventSPtr &anEvent ) const = 0;
	};

	typedef boost::shared_ptr< IEventManager > IEventManagerSPtr;
}
