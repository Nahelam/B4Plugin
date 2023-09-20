#ifndef B4P_DEBUG_DEBUG_MENU_STATE_H_INCLUDED
#define B4P_DEBUG_DEBUG_MENU_STATE_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "b4p_state.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugDebugMenuState CB4DebugDebugMenuState;

struct CB4DebugDebugMenuState { // 0x18
    CGtState mState;
    bool mbDebuggingProgression;
    uint8_t __pad0[7];
};

// --------------------------------
//    Declarations
// --------------------------------

void CB4DebugDebugMenuState__ActionHook(CB4DebugDebugMenuState* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4DebugDebugMenuState__Action_t)(CB4DebugDebugMenuState* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);

extern CB4DebugDebugMenuState__Action_t CB4DebugDebugMenuState__Action;

#endif
