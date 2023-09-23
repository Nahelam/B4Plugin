#ifndef B4P_MAIN_MENU_STATE_H_INCLUDED
#define B4P_MAIN_MENU_STATE_H_INCLUDED

#include <stdint.h>
#include "b4p_state.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4MainMenuState CB4MainMenuState;

struct CB4MainMenuState { // 0x10
    CGtState mState;
};

// --------------------------------
//    Declarations
// --------------------------------

void CB4MainMenuState__ActionHook(CB4MainMenuState* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*CB4MainMenuState__Action_t)(CB4MainMenuState* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
typedef void (*CB4MainMenuState__InitiateConfirm_t)(CB4MainMenuState* _this, uint64_t lDestinationState);

extern CB4MainMenuState__Action_t CB4MainMenuState__Action;
extern CB4MainMenuState__InitiateConfirm_t CB4MainMenuState__InitiateConfirm;

#endif
