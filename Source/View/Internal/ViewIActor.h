#pragma once


namespace View
{
	class Renderer;
	typedef boost::shared_ptr< Renderer > RendererSPtr;
}


namespace View {
	class IActor {
	public:		virtual unsigned int getActorId( void ) const = 0;
				virtual void setTransformation( const Utilities::Transformation &aTransformation ) = 0;
				virtual void appendRenderJob( const RendererSPtr &aRenderer ) = 0;
	};

	typedef boost::shared_ptr< IActor > IActorSPtr;
}
