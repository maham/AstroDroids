#pragma once


// Windows
//
#include <windows.h>
#include <cassert>
#include <cmath>

// STL
//
#include <exception>
#include <string>
#include <map>
#include <vector>
#include <queue>

// Utilities
//
#include <UtilitiesEvent.h>
#include <UtilitiesEventManager.h>
#include <UtilitiesHashedString.h>
#include <UtilitiesIEventListener.h>
#include <UtilitiesVector.h>
#include <UtilitiesCollision.h>
#include <UtilitiesGeometry.h>

// Common
//

// TiCPP
//
#include <ticpp.h>


// DirectX
#define DIRECTINPUT_VERSION 0x800
#include <dinput.h>
#include <XInput.h>

// HGE
//
#include <hge.h>
#include <hgeSprite.h>
#include <hgeFont.h>


// Boost
//
#include <boost/shared_ptr.hpp>


class HGE;
typedef boost::shared_ptr< HGE > HGESPtr;

class hgeSprite;
typedef boost::shared_ptr< hgeSprite > hgeSpriteSPtr;

class hgeFont;
typedef boost::shared_ptr< hgeFont > hgeFontSPtr;


// View
//
namespace View
{
	class Manager;
	typedef boost::shared_ptr< Manager > ManagerSPtr;

	class IManager;
	typedef boost::shared_ptr< IManager > IManagerSPtr;

	class ResourceManager;
	typedef boost::shared_ptr< ResourceManager > ResourceManagerSPtr;

	class Renderer;
	typedef boost::shared_ptr< Renderer > RendererSPtr;

	class Input;
	typedef boost::shared_ptr< Input > InputSPtr;

	class IActor;
	typedef boost::shared_ptr< IActor > IActorSPtr;
}

