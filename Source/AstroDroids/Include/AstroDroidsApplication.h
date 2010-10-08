#pragma once


// Forward declarations
//
namespace View
{
	class IManager;
	typedef boost::shared_ptr< IManager > IManagerSPtr;
}


namespace AstroDroids
{
	class Application
	{
	public:		Application( void );

				bool update( void );

	private:	View::IManagerSPtr	_viewManager;
				__int64				_frequency,
									_lastCounter;
	};
}
