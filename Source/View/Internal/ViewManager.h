#pragma once


#include "ViewIManager.h"

// Forward declarations
//


namespace View
{
	class Manager : public IManager
	{
	public:		Manager( const std::string &aSettingsFile );
				virtual ~Manager();

				void loadSettings( const std::string &aSettingsFile );
				bool update( const float aDeltaTime );

				// Utilities::IEventListener interface
				//
				bool handleEvent( const Utilities::IEventSPtr &anEvent );
				
	private:	typedef std::map< unsigned long, IActorSPtr > ActorMap;
				typedef std::vector< IActorSPtr > ActorVector;
				const Manager &operator =( const Manager &aSource );
				
				HGESPtr						_HGE;
				ResourceManagerSPtr			_resourceManager;
				RendererSPtr				_renderer;
				InputSPtr					_input;
				ActorMap					_actors;
	};
}
