#pragma once


// Forward declarations
//
namespace boost {
	template< typename TYPE >
	class shared_ptr;
}

namespace std {
	template< typename TYPE1, typename TYPE2 >
	class list;
}

namespace Utilities {
	class ITimer;
	typedef boost::shared_ptr< ITimer > ITimerSPtr;
	typedef std::list< ITimerSPtr > ITimerList;
}


namespace Utilities {
	class ITimer {
	public:		virtual void OnUpdate( const float aDeltaT ) = 0;
				virtual void AttachTimer( const ITimerSPtr &aTimer ) = 0;
				virtual void DetatchTimer( const ITimerSPtr &aTimer ) = 0;
	};
}
