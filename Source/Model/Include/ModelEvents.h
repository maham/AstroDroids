#pragma once


namespace Model
{
	struct ActorProperties;
}


namespace Model
{
	class QuitEvent : public Utilities::BaseEvent {
	public:		explicit QuitEvent( void );
				static const Utilities::EventType Type;
				
				inline const Utilities::EventType &GetEventType( void ) const { return Type; }
	};

	typedef boost::shared_ptr< QuitEvent > QuitEventSPtr;


	struct ActorCreatedEvent : public Utilities::BaseEvent {
		explicit ActorCreatedEvent( const ActorProperties &someActorProperties );
		static const Utilities::EventType Type;
		
		inline const Utilities::EventType &GetEventType( void ) const { return Type; }

		const ActorProperties &properties;
	};

	typedef boost::shared_ptr< ActorCreatedEvent > ActorCreatedEventSPtr;


	struct ActorMovedEvent : public Utilities::BaseEvent {
		explicit ActorMovedEvent( const unsigned int anActorId, const Utilities::Transformation &aTransformation );
		static const Utilities::EventType Type;
		
		inline const Utilities::EventType &GetEventType( void ) const { return Type; }

		const unsigned int actorId;
		const Utilities::Transformation &transformation;
	};

	typedef boost::shared_ptr< ActorMovedEvent > ActorMovedEventSPtr;
}
