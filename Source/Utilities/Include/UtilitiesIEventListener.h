#pragma once


// Forward declarations
//
namespace boost{
	template< typename TYPE >
	class shared_ptr;
}

namespace Utilities {
	class IEvent;
	typedef boost::shared_ptr< IEvent > IEventSPtr;
}


namespace Utilities {
	class IEventListener {
	public:		virtual bool handleEvent( const IEventSPtr &anEvent ) = 0;
	};

	typedef boost::shared_ptr< IEventListener > IEventListenerSPtr;
}
