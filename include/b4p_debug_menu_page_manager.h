#ifndef B4P_DEBUG_MENU_PAGE_MANAGER_H_INCLUDED
#define B4P_DEBUG_MENU_PAGE_MANAGER_H_INCLUDED

#include "b4p_debug_menu_page_base.h"
#include "b4p_debug_menu_component_base.h"
#include "b4p_menu_flow_manager.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugMenuPageManager CB4DebugMenuPageManager;

struct CB4DebugMenuPageManager { // 0x10
    float mRenderSize[2]; // CGtV2d
    CB4DebugMenuPageBase *mpCurrentPage;
    CB4DebugMenuComponentBase *mpFirstComponent;
};

// --------------------------------
//    Declarations
// --------------------------------


// --------------------------------
//    B4 Variables
// --------------------------------

extern CB4DebugMenuPageManager* gDebugMenuPageManager;

// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4DebugMenuPageManager__ImmediateLeadOut_t)(void* _this, EB4MenuFlowEvents leEvent);

extern CB4DebugMenuPageManager__ImmediateLeadOut_t CB4DebugMenuPageManager__ImmediateLeadOut;

#endif
