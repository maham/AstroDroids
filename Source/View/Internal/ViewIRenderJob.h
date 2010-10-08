#ifndef _VIEW_IRENDERJOB_H_
#define _VIEW_IRENDERJOB_H_


namespace View
{
	typedef class IRenderJob
	{
	public:		virtual void Render( void ) = 0;
	} *IRenderJobPtr;
}


#endif // _VIEW_IRENDERJOB_H_
