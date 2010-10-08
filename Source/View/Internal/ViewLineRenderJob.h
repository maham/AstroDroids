#ifndef _VIEW_LINERENDERJOB_H_
#define _VIEW_LINERENDERJOB_H_


#include "ViewIRenderJob.h"


// Forward declarations
//
namespace boost{
	template< typename TYPE >
	class shared_ptr;
}

class HGE;
typedef boost::shared_ptr< HGE > HGESPtr;



namespace View
{
	class LineRenderJob : public IRenderJob
	{
	public:		LineRenderJob( HGESPtr &aHGE, const Utilities::Vector2 &aStartPosition, const Utilities::Vector2 &anEndPosition, const int aColor );
				
				void Render( void );
				
	private:	const LineRenderJob &operator =( const LineRenderJob &aSource );
				
				const Utilities::Vector2	myStartPosition,
										myEndPosition;
				const int	myColor;
				HGESPtr &myHGE;
	};
}


#endif // _VIEW_LINERENDERJOB_H_
