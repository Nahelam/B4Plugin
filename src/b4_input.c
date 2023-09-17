#include "b4_input.h"

// ================================================================

void* gInputManager = 0x4F33C0;

float (*CB4ControllerMapping__GetPadControl)(void* _this, EGtPS2DualShockDeviceControl lePadControl, bool lbDebounced, uint8_t ln8Player) = 0x113000;
bool (*CB4InputManager__GetMenuButton)(void* _this, EMenuControls leMenuButton, int8_t ln8Player) = 0x105C48;

// ================================================================
