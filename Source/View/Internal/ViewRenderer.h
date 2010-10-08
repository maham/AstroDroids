#pragma once


namespace View
{
	class Manager;
	typedef boost::shared_ptr< Manager > ManagerSPtr;
	class IRenderJob;
	typedef boost::shared_ptr< IRenderJob > IRenderJobSPtr;
}


namespace View
{
	class Renderer
	{
	public:		Renderer( const HGESPtr &aHGE );
				~Renderer();

				void AppendJob( IRenderJobSPtr &aRenderJob );
				void Render( void );
				
	private:	const Renderer &operator =( const Renderer &aSource );
				
				std::vector< IRenderJobSPtr >	myRenderQueue;
				HGESPtr							_HGE;
	};

	typedef boost::shared_ptr< Renderer > RendererSPtr;
}
