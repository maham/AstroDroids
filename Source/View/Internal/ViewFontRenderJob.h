#ifndef _VIEW_FONTRENDERJOB_H_
#define _VIEW_FONTRENDERJOB_H_


#include "ViewIRenderJob.h"

// Forward declarations
//
class hgeFont;


namespace View
{
	class FontRenderJob : public IRenderJob
	{
	public:		FontRenderJob( hgeFontSPtr &aFont, const Utilities::Vector2 &aPosition, const int anAlignment, const std::string &aString );
				
				void Render( void );
				
	private:	const FontRenderJob &operator =( const FontRenderJob &aSource );
				
				hgeFontSPtr myFont;
				const Utilities::Vector2 myPosition;
				const int myAlignment;
				const std::string myText;
	};
}


#endif // _VIEW_FONTRENDERJOB_H_
