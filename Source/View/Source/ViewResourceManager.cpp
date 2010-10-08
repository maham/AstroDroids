#include "Precompiled.h"

#include "ViewResourceManager.h"
#include "ViewException.h"
#include "ViewManager.h"


View::ResourceManager::ResourceManager( const HGESPtr &aHGE, const std::string &aResourceScript )
: myResourceDocument( new ticpp::Document( aResourceScript ) )
, _HGE( aHGE )
{
	myResourceDocument->LoadFile();
	
	if( myResourceDocument->FirstChildElement()->Value() != "gameresources" )
	{
		throw new View::Exception( "The given game resource script is not really a game resource script." );
	}
}


hgeSpriteSPtr View::ResourceManager::GetSprite( const std::string &aSpriteName )
{
	std::map< std::string, hgeSpriteSPtr >::iterator iter = mySprites.find( aSpriteName );
	if( iter != mySprites.end() )
	{
		return iter->second;
	}

	ticpp::Iterator< ticpp::Element > child( "sprite" );
	for( child = child.begin( myResourceDocument->FirstChildElement() ); child != child.end(); child++ )
	{
		if( child->GetAttribute( "name" ) == aSpriteName )
		{
			float	xPos,
					yPos,
					width,
					height,
					hotSpotX,
					hotSpotY;
			std::string	textureName;

			child->FirstChildElement()->GetAttribute( "name", &textureName );
			child->FirstChildElement()->GetAttribute( "x", &xPos );
			child->FirstChildElement()->GetAttribute( "y", &yPos );
			child->FirstChildElement()->GetAttribute( "width", &width );
			child->FirstChildElement()->GetAttribute( "height", &height );
			child->FirstChildElement()->NextSiblingElement()->GetAttribute( "x", &hotSpotX );
			child->FirstChildElement()->NextSiblingElement()->GetAttribute( "y", &hotSpotY );

			HTEXTURE spriteTexture = 0;
			
			if( textureName != "" )
				spriteTexture = GetTexture( textureName );
			
			hgeSpriteSPtr newSprite = hgeSpriteSPtr( new hgeSprite( spriteTexture, xPos, yPos, width, height ) );
			newSprite->SetHotSpot( hotSpotX, hotSpotY );
			mySprites[aSpriteName] = newSprite;
			return newSprite;
		}
	}

	throw new View::Exception( "No such sprite found!" );
}


HTEXTURE View::ResourceManager::GetTexture( const std::string &aTextureName )
{
	std::map< std::string, HTEXTURE >::iterator iter = myTextures.find( aTextureName );
	if( iter != myTextures.end() )
	{
		return iter->second;
	}

	ticpp::Iterator< ticpp::Element > child( "texture" );
	for( child = child.begin( myResourceDocument->FirstChildElement() ); child != child.end(); child++ )
	{
		if( child->GetAttribute( "name" ) == aTextureName )
		{
			std::string	textureFileName;

			child->GetAttribute( "filename", &textureFileName );

			HTEXTURE newTexture = _HGE->Texture_Load( textureFileName.c_str() );

			char *errorMessage;

			if( !newTexture )
			{
				errorMessage = _HGE->System_GetErrorMessage();
			}
			
			myTextures[aTextureName] = newTexture;

			return newTexture;
		}
	}

	throw new View::Exception( "No such texture found!" );
}


hgeFontSPtr View::ResourceManager::GetFont( const std::string &aFontName )
{
	std::map< std::string, hgeFontSPtr >::iterator iter = myFonts.find( aFontName );
	if( iter != myFonts.end() )
	{
		return iter->second;
	}

	ticpp::Iterator< ticpp::Element > child( "font" );
	for( child = child.begin( myResourceDocument->FirstChildElement() ); child != child.end(); child++ )
	{
		if( child->GetAttribute( "name" ) == aFontName )
		{
			std::string	fontFileName;

			child->GetAttribute( "filename", &fontFileName );

			hgeFontSPtr newFont( new hgeFont( fontFileName.c_str() ) );

			myFonts[aFontName] = newFont;

			return newFont;
		}
	}

	throw new View::Exception( "No such font found!" );
}
