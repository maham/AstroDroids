#pragma once


#include <exception>
#include <string>


namespace Utilities
{
	class Exception : public std::exception
	{
	public:		Exception( const std::string &someDetails );
				
				
				const char *what( void ) const throw()
				{
					return _details.c_str();
				}
				
	private:	std::string _details;
	};
}
