#ifndef _VIEW_SPRITERENDERJOB_H_
#define _VIEW_SPRITERENDERJOB_H_


#include "ViewIRenderJob.h"

// Forward declarations
//
class hgeSprite;


namespace View
{
	class SpriteRenderJob : public IRenderJob
	{
	public:		SpriteRenderJob( hgeSpriteSPtr &aSprite, const Utilities::Vector2 &aPosition, const float aRotation, const float aScale );
				
				void Render( void );
				
	private:	const SpriteRenderJob &operator =( const SpriteRenderJob &aSource );
				
				const Utilities::Vector2 myPosition;
				const float		myRotation,
								myScale;
				hgeSpriteSPtr	mySprite;
	};
}


#endif // _VIEW_SPRITERENDERJOB_H_
