#include "Precompiled.h"

#include "ViewFontRenderJob.h"


View::FontRenderJob::FontRenderJob( hgeFontSPtr &aFont, const Utilities::Vector2 &aPosition, const int anAlignment, const std::string &aString )
: myFont( aFont )
, myPosition( aPosition )
, myAlignment( anAlignment )
, myText( aString )
{
}


void View::FontRenderJob::Render( void )
{
	myFont->Render(
		myPosition.x,
		myPosition.y,
		myAlignment,
		myText.c_str() );
}
