#include "Precompiled.h"

#include "ViewException.h"



View::Exception::Exception( const std::string &someDetails )
: myDetails( someDetails )
{}


const char *View::Exception::what( void ) const
{
	return myDetails.c_str();
}
