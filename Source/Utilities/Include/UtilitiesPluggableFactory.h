#pragma once


#include <map>
#include <iostream>
#include "UtilitiesHashedString.h"
#include "UtilitiesException.h"


namespace Utilities
{
	template< typename TYPE >
	class PluggableFactory
	{
	public:		class Exception : public Utilities::Exception
				{
				public:		Exception( const std::string &someDetails )
							: Utilities::Exception( someDetails )
							{
							}
				};
				
				
				typedef std::map< unsigned long, PluggableFactory< TYPE > * > FactoryMap;
				
				
				PluggableFactory( const HashedString &anIdentifier )
				{
					FactoryMap::iterator currentFactory = _GetFactoryRegistry().find( anIdentifier.GetIdent() );
					
					if( currentFactory != _GetFactoryRegistry().end() )
					{
						throw Exception( "Hash for type already used." );
					}
					
					_GetFactoryRegistry()[anIdentifier.GetIdent()] = this;
				}
				
				
				static TYPE ConstructObject( std::istream &someData )
				{
					std::string type;
					someData >> type;
					FactoryMap::iterator factoryIterator = _GetFactoryRegistry().find( HashedString( type.c_str() ).GetIdent() );
					if( factoryIterator != _GetFactoryRegistry().end() )
					{
						return factoryIterator->second->MakeObject( someData );
					}
					
					throw new Exception( "Couldn't find a factory for the given type." );
				}
			 
	protected:	virtual TYPE MakeObject( std::istream &someData ) const = 0;
				static FactoryMap &_GetFactoryRegistry( void )
				{
					static FactoryMap factoryMap;
					return factoryMap;
				}
	};
}
