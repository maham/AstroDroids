#include "Precompiled.h"

#include "AstroDroidsException.h"



AstroDroids::Exception::Exception( const std::string &someDetails )
: myDetails( someDetails )
{}


const char *AstroDroids::Exception::what( void ) const
{
	return myDetails.c_str();
}
