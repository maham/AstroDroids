#pragma once


namespace View
{
	class Exception : public std::exception
	{
	public:		Exception( const std::string &someDetails );

				const char *what( void ) const throw();

	private:	std::string myDetails;
	};
}
