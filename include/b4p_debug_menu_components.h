#ifndef B4P_DEBUG_MENU_COMPONENTS_H_INCLUDED
#define B4P_DEBUG_MENU_COMPONENTS_H_INCLUDED

#include <stdint.h>
#include "b4p_debug_background_component.h"
#include "b4p_debug_vselect_component.h"
#include "b4p_debug_vselect_option_component.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugMenuComponents CB4DebugMenuComponents;

struct CB4DebugMenuComponents { // 0x40
    CB4DebugBackgroundComponent mBackground;
    CB4DebugVSelectComponent mVSelect;
    CB4DebugVSelectOptionComponent mVSelectOption;
    uint8_t __pad0[0xC]; // CB4DebugOnlineCarSelectComponent mOnlineCarSelect
};

// --------------------------------
//    Declarations
// --------------------------------


// --------------------------------
//    B4 Variables
// --------------------------------

extern CB4DebugMenuComponents* gDebugMenuComponents;

// --------------------------------
//    B4 Functions
// --------------------------------


#endif
