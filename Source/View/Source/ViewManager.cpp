#include "Precompiled.h"

#include "ViewActor.h"
#include "ViewManager.h"
#include "ViewResourceManager.h"
#include "ViewRenderer.h"
#include "ViewSpriteRenderJob.h"
#include "ViewFontRenderJob.h"
#include "ViewLineRenderJob.h"
#include "ViewInput.h"
#include "ViewException.h"
#include <ModelActors.h>
#include <ModelEvents.h>


View::Manager::Manager( const std::string &aSettingsFile ) {
	_HGE				= HGESPtr( hgeCreate( HGE_VERSION ) );
	_input				= InputSPtr( new Input( _HGE->System_GetState( HGE_HWND ) ) );
	_resourceManager	= ResourceManagerSPtr( new ResourceManager( _HGE, "resources.xml" ) );
	_renderer			= RendererSPtr( new Renderer( _HGE ) );

	loadSettings( aSettingsFile );

	if( _HGE->System_Initiate() != true )
	{
		throw new Exception( "Failed to initialize HGE." );
	}
}


View::Manager::~Manager() {
	_HGE->System_Shutdown();
	_HGE->Release();
}


void View::Manager::loadSettings( const std::string &aSettingsFile ) {
	ticpp::Document settingsDocument( aSettingsFile );
	settingsDocument.LoadFile();

	assert( settingsDocument.FirstChildElement()->Value() == "viewsettings" && "Loaded .xml file was not a ""gamesettings"" file." );

	ticpp::Iterator< ticpp::Element > child;
	for( child = child.begin( settingsDocument.FirstChildElement() ); child != child.end(); child++ ) {
		if( child->Value() == "log" ) {
			_HGE->System_SetState( HGE_LOGFILE, child->GetAttribute( "filename" ).c_str() );
		} else if( child->Value() == "screen" ) {
			_HGE->System_SetState( HGE_SCREENWIDTH, child->GetAttribute< int >( "screenwidth" ) );
			_HGE->System_SetState( HGE_SCREENHEIGHT, child->GetAttribute< int >( "screenheight" ) );
			_HGE->System_SetState( HGE_SCREENBPP, child->GetAttribute< int >( "screenbpp" ) );

			if( child->HasAttribute( "windowed" ) ) {
				_HGE->System_SetState( HGE_WINDOWED, child->GetAttribute< bool >( "windowed" ) );
			}

			if( child->HasAttribute( "showsplash" ) ) {
				_HGE->System_SetState( HGE_SHOWSPLASH, child->GetAttribute< bool >( "showsplash" ) );
			}
		} else if( child->Value() == "title" ) {
			_HGE->System_SetState( HGE_TITLE, child->GetAttribute( "name" ).c_str() );
		}
	}
}


bool View::Manager::update( const float aDeltaTime )
{
	_input->Update();

	if( _input->IsKeyDown( DIK_ESCAPE )
		|| _input->GetXboxController( 0 )->IsButtonDown( Input::XboxController::Back ) )
	{
		return false;
	}

	for( float y = 0.0f; y < 768.0f; y += 20 )
	{
		IRenderJobSPtr job( new LineRenderJob( _HGE, Utilities::Vector2( 0.0f, y ), Utilities::Vector2( 1024.f, y ), 0x20ff5555 ) );
		_renderer->AppendJob( job );
	}
	
	for( float x = 0.0f; x < 1024.0f; x += 20 )
	{
		IRenderJobSPtr job( new LineRenderJob( _HGE, Utilities::Vector2( x, 0.0f ), Utilities::Vector2( x, 768.0f ), 0x205555ff ) );
		_renderer->AppendJob( job );
	}

	if( _actors.size() > 0 )
	{
		for( ActorMap::const_iterator currentActorIterator = _actors.begin(); currentActorIterator != _actors.end(); currentActorIterator++ ) {
			IActorSPtr currentActor = currentActorIterator->second;
			currentActor->appendRenderJob( _renderer );
		}
	}
	hgeFontSPtr font( _resourceManager->GetFont( "Font1" ) );
	IRenderJobSPtr job( new FontRenderJob( font, Utilities::Vector2( 10.0f, 10.0f ), HGETEXT_LEFT, "3llo wrld" ) );
	_renderer->AppendJob( job );

	_renderer->Render();
	
	return true;
}


bool View::Manager::handleEvent( const Utilities::IEventSPtr &anEvent ) {
	if( anEvent->GetEventType() == Model::ActorCreatedEvent::Type ) {
		const Model::ActorCreatedEventSPtr actorCreatedEvent = boost::static_pointer_cast< Model::ActorCreatedEvent, Utilities::IEvent >( anEvent );
		const Model::ActorProperties &actorProperties = actorCreatedEvent->properties;
		
		if( actorProperties.type == Model::ActorProperties::Type ) {
			hgeRect rect;
			hgeSpriteSPtr shipSprite( _resourceManager->GetSprite( "ship" ) );
			shipSprite->GetTextureRect( &rect.x1, &rect.y1, &rect.x2, &rect.y2 );

			ActorSPtr actor( new Actor( _actors.size(), hgeSpriteSPtr( shipSprite ), actorProperties.transformation, actorProperties.radius / ( rect.x2 / 2.0f ) ) );
			_actors[actorProperties.id] = actor;
		}
	} else if( anEvent->GetEventType() == Model::ActorMovedEvent::Type ) {
		const Model::ActorMovedEventSPtr actorMovedEvent = boost::static_pointer_cast< Model::ActorMovedEvent, Utilities::IEvent >( anEvent );
		
		IActorSPtr actor = _actors.find( actorMovedEvent->actorId )->second;
		actor->setTransformation( actorMovedEvent->transformation );
	}
	return false;
}
