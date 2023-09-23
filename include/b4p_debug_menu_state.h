#ifndef B4P_DEBUG_MENU_STATE_H_INCLUDED
#define B4P_DEBUG_MENU_STATE_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "b4p_state.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugMenuState CB4DebugMenuState;

struct CB4DebugMenuState { // 0x18
    CGtState mState;
    bool mbDebuggingProgression;
    uint8_t __pad0[7];
};

// --------------------------------
//    Declarations
// --------------------------------

void CB4DebugMenuState__ActionHook(CB4DebugMenuState* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*CB4DebugMenuState__Action_t)(CB4DebugMenuState* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);

extern CB4DebugMenuState__Action_t CB4DebugMenuState__Action;

#endif
