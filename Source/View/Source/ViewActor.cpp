#include "Precompiled.h"

#include "ViewRenderer.h"
#include "ViewActor.h"
#include "ViewSpriteRenderJob.h"


View::Actor::Actor( const unsigned int anId, const hgeSpriteSPtr &aSprite, const Utilities::Transformation &aTransformation, const float aScale )
: _id( anId )
, _sprite( aSprite )
, _transformation( aTransformation )
, _scale( aScale )
{
}


void View::Actor::appendRenderJob( const RendererSPtr &aRenderer ) {
	IRenderJobSPtr job( new SpriteRenderJob( _sprite, _transformation.position, _transformation.orientation.Angle() + std::acos( -1.0f ) / 2.0f, _scale ) );
	aRenderer->AppendJob( job );
}
