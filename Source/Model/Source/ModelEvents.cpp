#include "Precompiled.h"
#include "ModelEvents.h"


const Utilities::EventType Model::QuitEvent::Type( "QuitEvent" );
const Utilities::EventType Model::ActorCreatedEvent::Type( "ActorCreatedEvent" );
const Utilities::EventType Model::ActorMovedEvent::Type( "ActorMovedEvent" );


Model::QuitEvent::QuitEvent( void )
{
}


Model::ActorCreatedEvent::ActorCreatedEvent( const ActorProperties &someActorProperties )
: properties( someActorProperties )
{
}


Model::ActorMovedEvent::ActorMovedEvent( const unsigned int anActorId, const Utilities::Transformation &aTransformation )
: actorId( anActorId )
, transformation( aTransformation )
{
}
