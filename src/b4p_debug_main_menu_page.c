#include "b4p_debug_main_menu_page.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_debug_menu_components.h"
#include "b4p_debug_background_component.h"
#include "b4p_debug_vselect_component.h"
#include "b4p_debug_menu_page_base.h"
#include "b4p_input.h"

static const char* kapcDebugMainMenuEntryNames[] = {
    "Test Menu",
    "Legacy Menu(with all its flaws)"
};

void CB4DebugMainMenuPage__Update(CB4DebugMainMenuPage* _this)
{
    if (CB4InputManager__GetMenuButton(gInputManager, eButtonBack, -1))
    {
        CB4DebugMenuPageManager__ImmediateLeadOut2(gDebugMenuPageManager, eMenuFlowEventMenuPageBack);
    }

    else if (CB4InputManager__GetMenuButton(gInputManager, eButtonConfirm, -1))
    {
        CB4DebugMenuPageManager__ImmediateLeadOut2(gDebugMenuPageManager, eMenuFlowEventMenuPageForward);
    }
}

void CB4DebugMainMenuPage__Release(CB4DebugMainMenuPage* _this)
{

}

void CB4DebugMainMenuPage__Prepare(CB4DebugMainMenuPage* _this)
{
    CB4DebugMenuPageBase__Prepare(&_this->mBase);
    CB4DebugBackgroundComponent__Prepare(&gDebugMenuComponents->mBackground);
    CB4DebugVSelectComponent__Prepare(&gDebugMenuComponents->mVSelect, kapcDebugMainMenuEntryNames, COUNT_OF(kapcDebugMainMenuEntryNames));
}
