#pragma once


#include "ViewIRenderJob.h"


// Forward declarations
//
namespace Model
{
	class Entity;
}

namespace View
{
	class Renderer;
	class Exception;
}


namespace View
{
	class Entity : public View::IRenderJob
	{
	public:		Entity( const Model::Entity *const aModel, hgeSprite *aSprite );

				hgeSprite *const GetSprite( void ) const throw( ... );
				const float GetXPosition( void ) const;
				const float GetYPosition( void ) const;

				void Draw( Renderer *const aRenderer );

	private:	const Model::Entity *const myModel;
				hgeSprite *mySprite;
	};
}
