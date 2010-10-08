#pragma once


#include "ViewIActor.h"


namespace View
{
	class Renderer;
	typedef boost::shared_ptr< Renderer > RendererSPtr;
}


namespace View
{
	class Actor : public IActor
	{
	public:		Actor( const unsigned int anId, const hgeSpriteSPtr &aSprite, const Utilities::Transformation &aTransformation, const float aScale );
				
				inline unsigned int getActorId( void ) const { return _id; }
				inline void setTransformation( const Utilities::Transformation &aTransformation ) { _transformation = aTransformation; }
				void appendRenderJob( const RendererSPtr &aRenderer );

	private:	unsigned int				_id;
				hgeSpriteSPtr				_sprite;
				Utilities::Transformation	_transformation;
				float						_scale;
	};

	typedef boost::shared_ptr< Actor > ActorSPtr;
}
