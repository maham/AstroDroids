#include "Precompiled.h"


#include "ViewManager.h"
#include "ViewRenderer.h"
#include "ViewIRenderJob.h"


View::Renderer::Renderer( const HGESPtr &aHGE )
: _HGE( aHGE )
{
}


View::Renderer::~Renderer()
{
}


void View::Renderer::AppendJob( IRenderJobSPtr &aRenderJob )
{
	myRenderQueue.push_back( aRenderJob );
}


void View::Renderer::Render( void )
{
	_HGE->Gfx_BeginScene();
	_HGE->Gfx_Clear( 0 );

	for( std::vector< IRenderJobSPtr >::iterator currentJobIterator = myRenderQueue.begin(); currentJobIterator != myRenderQueue.end(); ++currentJobIterator )
	{
		IRenderJobSPtr currentJob = *currentJobIterator;
		currentJob->Render();
	}
	
	myRenderQueue.clear();

	_HGE->Gfx_EndScene();
}
