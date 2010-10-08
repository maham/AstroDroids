#include "UtilitiesEventManager.h"
#include "UtilitiesEvent.h"
#include "UtilitiesIEventListener.h"


Utilities::EventManager::EventManager( void )
{}


Utilities::EventManager::~EventManager( void )
{}


void Utilities::EventManager::AddEventListener( const IEventListenerSPtr &aListener, const EventType &aType )
{
	EventListenerMap::iterator i = _eventListenerRegistry.find( aType.GetIdent() );
	
	if( i == _eventListenerRegistry.end() )
	{
		_eventListenerRegistry.insert( EventListenerMapEntry( aType.GetIdent(), EventListenerList() ) );
	}
	
	_eventListenerRegistry[aType.GetIdent()].push_back( aListener );
}


void Utilities::EventManager::RemoveEventListener( const IEventListenerSPtr &aListener, const EventType &aType ) {
	EventListenerMap::iterator foundEventListenerList = _eventListenerRegistry.find( aType.GetIdent() );
	
	if( foundEventListenerList == _eventListenerRegistry.end() )
		return;
	
	for( EventListenerList::iterator currentListenerIterator = foundEventListenerList->second.begin(); currentListenerIterator != foundEventListenerList->second.end(); ++currentListenerIterator ) {
		if( *currentListenerIterator == aListener ) {
			foundEventListenerList->second.erase( currentListenerIterator );
			return;
		}
	}
}


bool Utilities::EventManager::TriggerEvent( const IEventSPtr &anEvent ) const
{
	EventListenerMap::const_iterator i = _eventListenerRegistry.find( anEvent->GetEventType().GetIdent() );
	
	if( i != _eventListenerRegistry.end() )
	{
		for( EventListenerList::const_iterator currentListenerIterator = i->second.begin(); currentListenerIterator != i->second.end(); currentListenerIterator++ )
		{
			(*currentListenerIterator)->handleEvent( anEvent );
		}
	}
	
	return false;
}
