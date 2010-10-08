#pragma once


#include <string>
#include <map>


// Forward declarations
//
class HGE;
class hgeSprite;
class hgeFont;
typedef unsigned long HTEXTURE;

namespace ticpp
{
	class Document;
	typedef boost::shared_ptr< Document > DocumentSPtr;
}

namespace View
{
	class Manager;
	typedef boost::shared_ptr< Manager > ManagerSPtr;
	class IResource;
}


namespace View
{
	class ResourceManager
	{
	public:		ResourceManager( const HGESPtr &aHGE, const std::string &aResourceScript );

				hgeSpriteSPtr GetSprite( const std::string &aSpriteName );
				HTEXTURE GetTexture( const std::string &aTextureName );
				hgeFontSPtr GetFont( const std::string &aTextureName );

	private:	const ResourceManager &operator =( const ResourceManager &aSource );
				
				ticpp::DocumentSPtr myResourceDocument;
				std::map< std::string, hgeSpriteSPtr >	mySprites;
				std::map< std::string, HTEXTURE >		myTextures;
				std::map< std::string, hgeFontSPtr >		myFonts;
				const HGESPtr _HGE;
	};

	typedef boost::shared_ptr< ResourceManager > ResourceManagerSPtr;
}
