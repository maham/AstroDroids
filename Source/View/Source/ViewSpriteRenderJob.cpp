#include "Precompiled.h"

#include "ViewSpriteRenderJob.h"


View::SpriteRenderJob::SpriteRenderJob( hgeSpriteSPtr &aSprite, const Utilities::Vector2 &aPosition, const float aRotation, const float aScale )
: mySprite( aSprite )
, myPosition( aPosition )
, myRotation( aRotation )
, myScale( aScale )
{
}


void View::SpriteRenderJob::Render( void )
{
	mySprite->RenderEx(
		myPosition.x,
		myPosition.y,
		myRotation,
		myScale );
}
