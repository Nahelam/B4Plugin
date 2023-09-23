#ifndef B4P_INPUT_H_INCLUDED
#define B4P_INPUT_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

// --------------------------------
//    Enums
// --------------------------------

typedef enum {
    eGtPS2DualShock_Control_Triangle = 0,
    eGtPS2DualShock_Control_Square = 1,
    eGtPS2DualShock_Control_Cross = 2,
    eGtPS2DualShock_Control_Circle = 3,
    eGtPS2DualShock_Control_Dpad_Up = 4,
    eGtPS2DualShock_Control_Dpad_Down = 5,
    eGtPS2DualShock_Control_Dpad_Left = 6,
    eGtPS2DualShock_Control_Dpad_Right = 7,
    eGtPS2DualShock_Control_Start = 8,
    eGtPS2DualShock_Control_Select = 9,
    eGtPS2DualShock_Control_Left_Shoulder_1 = 10,
    eGtPS2DualShock_Control_Left_Shoulder_2 = 11,
    eGtPS2DualShock_Control_Right_Shoulder_1 = 12,
    eGtPS2DualShock_Control_Right_Shoulder_2 = 13,
    eGtPS2DualShock_Control_Left_Thumb = 14,
    eGtPS2DualShock_Control_Right_Thumb = 15,
    eGtNum_Of_PS2DualShock_Buttons = 16,
    eGtPS2DualShock_Control_Left_Stick_Up = 16,
    eGtPS2DualShock_Control_Left_Stick_Down = 17,
    eGtPS2DualShock_Control_Left_Stick_Left = 18,
    eGtPS2DualShock_Control_Left_Stick_Right = 19,
    eGtPS2DualShock_Control_Right_Stick_Up = 20,
    eGtPS2DualShock_Control_Right_Stick_Down = 21,
    eGtPS2DualShock_Control_Right_Stick_Left = 22,
    eGtPS2DualShock_Control_Right_Stick_Right = 23,
    eGtPS2DualShock_Control_Left_Stick_X = 24,
    eGtPS2DualShock_Control_Left_Stick_Y = 25,
    eGtPS2DualShock_Control_Right_Stick_X = 26,
    eGtPS2DualShock_Control_Right_Stick_Y = 27,
    eGtNum_Of_PS2DualShock_Controls = 28
} EGtPS2DualShockDeviceControl;

typedef enum {
    eButtonLeft = 0,
    eButtonRight = 1,
    eButtonUp = 2,
    eButtonDown = 3,
    eButtonStart = 4,
    eButtonSelect = 5,
    eButtonConfirm = 6,
    eButtonConfirmNotStart = 7,
    eButtonBack = 8,
    eButtonRestart = 9,
    eButtonTalk = 10,
    eButtonStartRace = 11,
    eButtonBuddies = 12,
    eButtonDeletePersona = 13,
    eButtonKeyboardShift = 14,
    eButtonKeyboardCapsLock = 15,
    eButtonKeyboardSymbols = 16,
    eButtonKeyboardAccents = 17,
    eButtonPageUp = 18,
    eButtonPageDown = 19,
    eButtonSwitchTeams = 20,
    eButtonChangeColour = 21,
    eButtonChangeNames = 22,
    eButtonAppearOffline = 23,
    eButtonSearchBuddy = 24,
    eNumButtons = 25
} EMenuControls;

// --------------------------------
//    Structs
// --------------------------------


// --------------------------------
//    Declarations
// --------------------------------


// --------------------------------
//    B4 Variables
// --------------------------------

extern void* gInputManager;

// --------------------------------
//    B4 Functions
// --------------------------------

typedef float (*CB4ControllerMapping__GetPadControl_t)(void* _this, EGtPS2DualShockDeviceControl lePadControl, bool lbDebounced, uint8_t ln8Player);
typedef bool (*CB4InputManager__GetMenuButton_t)(void* _this, EMenuControls leMenuButton, int8_t ln8Player);

extern CB4ControllerMapping__GetPadControl_t CB4ControllerMapping__GetPadControl;
extern CB4InputManager__GetMenuButton_t CB4InputManager__GetMenuButton;

#endif
