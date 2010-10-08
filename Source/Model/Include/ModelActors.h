#pragma once


namespace Model
{
	typedef Utilities::HashedString ActorType;


	struct ActorProperties
	{
		ActorProperties( void );
		ActorProperties( const ActorType &anActorType );
		
		unsigned int				id;
		Utilities::Transformation	transformation;
		float						radius;
		ActorType					type;
		
		static const ActorType Type;
	};

	typedef boost::shared_ptr< ActorProperties > ActorPropertiesSPtr;


	struct ShipActorProperties : public ActorProperties
	{
		ShipActorProperties( void );
		
		static const ActorType Type;

	};

	typedef boost::shared_ptr< ShipActorProperties > ShipActorPropertiesSPtr;
}
