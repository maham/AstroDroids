#pragma once

namespace View
{
	class Input
	{
	public:		typedef char KEYSET [256];

				typedef class XboxController
				{
				public:		enum ControllerButton
							{
								DPadUp			= XINPUT_GAMEPAD_DPAD_UP,
								DPadDown		= XINPUT_GAMEPAD_DPAD_DOWN,
								DPadLeft		= XINPUT_GAMEPAD_DPAD_LEFT,
								DPadRight		= XINPUT_GAMEPAD_DPAD_RIGHT,
								Start			= XINPUT_GAMEPAD_START,
								Back			= XINPUT_GAMEPAD_BACK,
								LeftThumb		= XINPUT_GAMEPAD_LEFT_THUMB,
								RightThumb		= XINPUT_GAMEPAD_RIGHT_THUMB,
								LeftShoulder	= XINPUT_GAMEPAD_LEFT_SHOULDER,
								RightShoulder	= XINPUT_GAMEPAD_RIGHT_SHOULDER,
								A				= XINPUT_GAMEPAD_A,
								B				= XINPUT_GAMEPAD_B,
								X				= XINPUT_GAMEPAD_X,
								Y				= XINPUT_GAMEPAD_Y
							};
							
							
							enum ControllerThumbAxis
							{
								LeftThumbX,
								LeftThumbY,
								RightThumbX,
								RightThumbY,
							};
							
							
							enum ControllerTrigger
							{
								LeftTrigger,
								RightTrigger,
							};
							
							
							XboxController( const int aPlayerNumber );
							void Update( void );
							void Init( void );
							bool IsButtonDown( const ControllerButton aButton ) const;
							float GetThumbAxis( const ControllerThumbAxis anAxis ) const;
							
				private:	XINPUT_STATE	myState;
							int				myNum;
				} *XboxControllerPtr, *const XboxControllerCPtr;
				
				Input( const HWND aWindowHandle );
				~Input();
				
				void Update( void );
				bool IsKeyDown( const unsigned int aKeyCode ) const;
				XboxControllerCPtr GetXboxController( const unsigned int aControllerIndex ) const;

				//const long				&absMouseX;							///< ConstRef to Input::myAbsMouseX
				//const long 				&absMouseY;							///< ConstRef to Input::myAbsMouseY
				const BYTE				&leftMouseButton;					///< ConstRef to Input::myMouseState::rgbButtons[0]
				const BYTE				&rightMouseButton;					///< ConstRef to Input::myMouseState::rgbButtons[1]
				const BYTE				&middleMouseButton;					///< ConstRef to Input::myMouseState::rgbButtons[2]
				const LONG				&mouseXDelta;						///< ConstRef to Input::myMouseState::lX
				const LONG				&mouseYDelta;						///< ConstRef to Input::myMouseState::lY
				const LONG				&mouseZDelta;						///< ConstRef to Input::myMouseSatet::lZ
				const KEYSET			&keys;								///< ConstRef to Input::myKeys
				
	private:	const Input &operator =( const Input &aSource );
				
				void InitKeyboard( const HWND aWindowHandle );
				void InitMouse( const HWND aWindowHandle );
				void InitJoystick( const HWND aWindowHandle );
				
				LPDIRECTINPUT8			myDirectInputObject;
				LPDIRECTINPUTDEVICE8	myKeyboardDevice,
										myMouseDevice;
				DIMOUSESTATE2			myMouseState;
				DIJOYSTATE2				myJoystickState;
				char					myKeys[256];
				DWORD					myNumMouseAxes,
										myNumMouseButtons;
				XboxControllerPtr		myXboxControllers[4];
				//long	myAbsMouseX,
				//		myAbsMouseY;

	};
}
