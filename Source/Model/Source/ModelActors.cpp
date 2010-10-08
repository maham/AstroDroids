#include "Precompiled.h"

#include "ModelActors.h"


const Model::ActorType Model::ActorProperties::Type( "UnknownActor" );
const Model::ActorType Model::ShipActorProperties::Type( "ShipActor" );


Model::ActorProperties::ActorProperties( void )
: type( Type )
, transformation( Utilities::Point2::Zero, Utilities::Vector2::Zero )
{
}


Model::ActorProperties::ActorProperties( const ActorType &anActorType )
: type( anActorType )
, transformation( Utilities::Point2::Zero, Utilities::Vector2::Zero )
{
}


Model::ShipActorProperties::ShipActorProperties( void )
: ActorProperties( Type )
{
}