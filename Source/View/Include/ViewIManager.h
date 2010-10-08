#pragma once


// Forward declarations
//


namespace View
{
	class IManager : public Utilities::IEventListener
	{
	public:		static IManagerSPtr Create( const std::string &aSettingsFile );

				virtual void loadSettings( const std::string &aSettingsFile ) = 0;
				virtual bool update( const float aDeltaTime ) = 0;

				// Utilities::IEventListener interface
				//
				virtual bool handleEvent( const Utilities::IEventSPtr &anEvent ) = 0;
				
	protected:	IManager( void );

	private:	static IManagerSPtr _Instance;
	};
}
