#include "Precompiled.h"

#include "ViewInput.h"
#include "ViewException.h"


View::Input::XboxController::XboxController( const int aPlayerNumber )
: myNum( aPlayerNumber )
{
}


void View::Input::XboxController::Update( void )
{
	XInputGetState( myNum, &myState );
	
	if(	( myState.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE
		&& myState.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE )
		&& ( myState.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE
		&& myState.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ) )
	{
		myState.Gamepad.sThumbLX = 0;
		myState.Gamepad.sThumbLY = 0;
	}

	if(	( myState.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE
		&& myState.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE )
		&& ( myState.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE
		&& myState.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE ) )
	{
		myState.Gamepad.sThumbRX = 0;
		myState.Gamepad.sThumbRY = 0;
	}
}


void View::Input::XboxController::Init( void )
{
	DWORD result = XInputGetState( myNum, &myState );

	if( result != ERROR_SUCCESS )
	{
		throw new Exception( "Failed to init XboxController" );
	}
}


bool View::Input::XboxController::IsButtonDown( const ControllerButton aButton ) const
{
	return ( myState.Gamepad.wButtons & aButton ) != 0;
}


float View::Input::XboxController::GetThumbAxis( const ControllerThumbAxis anAxis ) const
{
	switch( anAxis )
	{
	case LeftThumbX:
		return myState.Gamepad.sThumbLX / 32767.0f;
	
	case LeftThumbY:
		return myState.Gamepad.sThumbLY / 32767.0f;
	
	case RightThumbX:
		return myState.Gamepad.sThumbRX / 32767.0f;
	
	case RightThumbY:
		return myState.Gamepad.sThumbRY / 32767.0f;
	}
	
	return 0;
}


View::Input::Input( const HWND aWindowHandle )
: myDirectInputObject( NULL )
, myKeyboardDevice( NULL )
, myMouseDevice( NULL )
//, absMouseX( myAbsMouseX )
//, absMouseY( myAbsMouseY )
, leftMouseButton( myMouseState.rgbButtons[0] )
, rightMouseButton( myMouseState.rgbButtons[1] )
, middleMouseButton( myMouseState.rgbButtons[2] )
, mouseXDelta( myMouseState.lX )
, mouseYDelta( myMouseState.lY )
, mouseZDelta( myMouseState.lZ )
,keys( myKeys )
{
	if( FAILED( DirectInput8Create(
		GetModuleHandle( NULL ),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&myDirectInputObject,
		NULL ) ) )
	{
		throw new Exception( "Failed to retrieve DirectInput object!" );
	}

	InitKeyboard( aWindowHandle );
	InitMouse( aWindowHandle );

	for( unsigned int controllerIndex = 0; controllerIndex < 1; controllerIndex++ )
	{
		myXboxControllers[controllerIndex] = new XboxController( controllerIndex );
		//myXboxControllers[controllerIndex]->Init();
	}

	Update();
}


View::Input::~Input()
{
	if( myMouseDevice != NULL )
	{
		myMouseDevice->Unacquire();
		myMouseDevice->Release();
		myMouseDevice = NULL;
	}

	if( myKeyboardDevice != NULL )
	{
		myKeyboardDevice->Unacquire();
		myKeyboardDevice->Release();
		myKeyboardDevice = NULL;
	}

	if( myDirectInputObject != NULL )
	{
		myDirectInputObject->Release();
		myDirectInputObject = NULL;
	}
}


void View::Input::Update( void )
{
	HRESULT hr;

	hr = myKeyboardDevice->GetDeviceState( sizeof( myKeys ), (LPVOID)&myKeys );

	if( FAILED( hr ) )
	{
		throw new Exception( "Failed to get keyboard device state!" );
	}

	hr = myMouseDevice->GetDeviceState( sizeof( myMouseState ), (LPVOID)&myMouseState );

	if( hr == DIERR_INPUTLOST )
	{
		myMouseDevice->Acquire();
	}
	else if( FAILED( hr ) )
	{
		throw new Exception( "Failed to get mouse device state!" );
	}

	for( unsigned int controllerIndex = 0; controllerIndex < 1; controllerIndex++ )
	{
		myXboxControllers[controllerIndex]->Update();
	}
}


bool View::Input::IsKeyDown( const unsigned int aKeyCode ) const
{
	if( aKeyCode > 255 )
		throw new Exception( "aKeyCode was out of bounds!" );
	
	return ( myKeys[aKeyCode] & 0x80 ) != 0;
}


View::Input::XboxControllerCPtr View::Input::GetXboxController( const unsigned int aControllerIndex ) const
{
	if( aControllerIndex > 4 )
		throw new Exception( "aControllerIndex was out of bounds!" );
	
	return myXboxControllers[aControllerIndex];
}


void View::Input::InitKeyboard( const HWND aWindowHandle )
{
	if( FAILED( myDirectInputObject->CreateDevice(
		GUID_SysKeyboard,
		&myKeyboardDevice,
		NULL ) ) )
	{
		throw new Exception( "Failed to create keyboard device!" );
	}

	if( FAILED( myKeyboardDevice->SetDataFormat( &c_dfDIKeyboard ) ) )
	{
		throw new Exception( "Failed to set keyboard data format!" );
	}

	if( FAILED( myKeyboardDevice->SetCooperativeLevel(
		aWindowHandle,
		DISCL_BACKGROUND | DISCL_NONEXCLUSIVE ) ) )
	{
		throw new Exception( "Failed to set keyboard cooperative level!" );
	}

	if( FAILED( myKeyboardDevice->Acquire() ) )
	{
		throw new Exception( "Failed to aquire mouse device!" );
	}

}


void View::Input::InitMouse( const HWND aWindowHandle )
{
	if( FAILED( myDirectInputObject->CreateDevice(
		GUID_SysMouse,
		&myMouseDevice,
		NULL ) ) )
	{
		throw new Exception( "Failed to create mouse device!" );
	}
	
	if( FAILED( myMouseDevice->SetDataFormat( &c_dfDIMouse2 ) ) )
	{
		throw new Exception( "Failed to set mouse data format!" );
	}

	if( FAILED( myMouseDevice->SetCooperativeLevel(
		aWindowHandle,
		DISCL_BACKGROUND | DISCL_NONEXCLUSIVE ) ) )
	{
		throw new Exception( "Failed to set mouse cooperative level!" );
	}

	if( FAILED( myMouseDevice->Acquire() ) )
	{
		throw new Exception( "Failed to aquire mouse device!" );
	}

	DIDEVCAPS mouseCapabilities;
	mouseCapabilities.dwSize = sizeof( mouseCapabilities );
	myMouseDevice->GetCapabilities( &mouseCapabilities );

	if( !mouseCapabilities.dwFlags &  DIDC_ATTACHED )
	{
		throw new Exception( "No mouse attached!" );
	}

	myNumMouseAxes = mouseCapabilities.dwAxes;
	myNumMouseButtons = mouseCapabilities.dwButtons;
}


void View::Input::InitJoystick( const HWND aWindowHandle )
{
	if( FAILED( myDirectInputObject->CreateDevice(
		GUID_Joystick,
		&myMouseDevice,
		NULL ) ) )
	{
		throw new Exception( "Failed to create mouse device!" );
	}
	
	if( FAILED( myMouseDevice->SetDataFormat( &c_dfDIMouse2 ) ) )
	{
		throw new Exception( "Failed to set mouse data format!" );
	}

	if( FAILED( myMouseDevice->SetCooperativeLevel(
		aWindowHandle,
		DISCL_BACKGROUND | DISCL_NONEXCLUSIVE ) ) )
	{
		throw new Exception( "Failed to set mouse cooperative level!" );
	}

	if( FAILED( myMouseDevice->Acquire() ) )
	{
		throw new Exception( "Failed to aquire mouse device!" );
	}

}
