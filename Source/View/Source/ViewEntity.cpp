#include "ModelEntity.h"
#include "ViewEntity.h"
#include "ViewRenderer.h"
#include "ViewIRenderJob.h"


View::Entity::Entity( const Model::Entity *const aModel, hgeSprite *aSprite )
: myModel( aModel )
, mySprite( aSprite )
{
}


hgeSprite *const View::Entity::GetSprite( void ) const
{
	return mySprite;
}


const float View::Entity::GetXPosition( void ) const
{
	return static_cast< float >( myModel->xPosition );
}


const float View::Entity::GetYPosition( void ) const
{
	return static_cast< float >( myModel->yPosition );
}

				
void View::Entity::Draw( View::Renderer *const aRenderer )
{
	aRenderer->AppendJob( this );
}
