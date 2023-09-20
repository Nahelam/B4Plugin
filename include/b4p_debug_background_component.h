#ifndef B4P_DEBUG_BACKGROUND_COMPONENT_H_INCLUDED
#define B4P_DEBUG_BACKGROUND_COMPONENT_H_INCLUDED

#include "b4p_debug_menu_component_base.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugBackgroundComponent CB4DebugBackgroundComponent;

struct CB4DebugBackgroundComponent { // 0xC
    CB4DebugMenuComponentBase mBase;
};

// --------------------------------
//    Declarations
// --------------------------------


// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4DebugBackgroundComponent__Prepare_t)(CB4DebugBackgroundComponent* _this);

extern CB4DebugBackgroundComponent__Prepare_t CB4DebugBackgroundComponent__Prepare;

#endif
