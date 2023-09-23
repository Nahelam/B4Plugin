#include "b4p_debug_original_menu_page.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_menu_flow_manager.h"
#include "b4p_input.h"

void CB4DebugOriginalMenuPage__UpdateHook(CB4DebugOriginalMenuPage* _this)
{
    if (CB4InputManager__GetMenuButton(gInputManager, eButtonBack, -1))
    {
        CB4DebugMenuPageManager__ImmediateLeadOut2(gDebugMenuPageManager, eMenuFlowEventMenuPageBack);
    }
    
    else
    {
        CB4DebugOriginalMenuPage__Update(_this);
    }
}
