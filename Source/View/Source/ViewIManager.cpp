#include "Precompiled.h"

#include "ViewIManager.h"
#include "ViewManager.h"


View::IManagerSPtr View::IManager::_Instance;


View::IManagerSPtr View::IManager::Create( const std::string &aSettingsFile ) {
	if( _Instance.get() == NULL ) {
		_Instance = IManagerSPtr( new Manager( aSettingsFile ) );
	}

	return _Instance;
}


View::IManager::IManager( void ) {

}