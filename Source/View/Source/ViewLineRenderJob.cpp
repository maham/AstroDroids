#include "Precompiled.h"

#include "ViewLineRenderJob.h"


View::LineRenderJob::LineRenderJob( HGESPtr &aHGE, const Utilities::Vector2 &aStartPosition, const Utilities::Vector2 &anEndPosition, const int aColor )
: myStartPosition( aStartPosition )
, myEndPosition( anEndPosition )
, myColor( aColor )
, myHGE( aHGE )
{
}


void View::LineRenderJob::Render( void )
{
	myHGE->Gfx_RenderLine( myStartPosition.x, myStartPosition.y, myEndPosition.x, myEndPosition.y, myColor );
}
