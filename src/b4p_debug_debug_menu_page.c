#include "b4p_debug_debug_menu_page.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_debug_menu_page_base.h"
#include "b4p_debug_debug_menu_entries.h"
#include "b4p_debug_menu_components.h"
#include "b4p_debug_background_component.h"
#include "b4p_debug_vselect_option_component.h"
#include "b4p_input.h"
#include "b4p_other.h"

CB4DebugVSelectEntry gaDebugMenuEntries[sizeof(gapcDebugMenuEntryNames) / sizeof(gapcDebugMenuEntryNames[0])];

void CB4DebugDebugMenuPage__UpdateHook(CB4DebugDebugMenuPage* _this)
{
    if (CB4InputManager__GetMenuButton(gInputManager, eButtonBack, -1))
    {
        CB4DebugMenuPageManager__ImmediateLeadOut(gDebugMenuPageManager, eMenuFlowEventMenuPageBack);
    }

    /*
    else if (CB4InputManager__GetMenuButton(gInputManager, eButtonConfirm, -1))
    {
    }
    */
}

void CB4DebugDebugMenuPage__PrepareHook(CB4DebugDebugMenuPage* _this)
{
    static bool lbEntriesPrepared = false;

    CB4DebugMenuPageBase__Prepare(&_this->mBase);

    if (!lbEntriesPrepared)
    {
        lbEntriesPrepared = true;
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[0], gapcDebugMenuEntryNames[0], gapcDebugMenuEntryVideoModeOptions, sizeof(gapcDebugMenuEntryVideoModeOptions) / sizeof(gapcDebugMenuEntryVideoModeOptions[0]), gGraphicsManager->meCurrentVideoMode);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[1], gapcDebugMenuEntryNames[1], gapcDebugMenuEntrySpeedoUnitOptions, sizeof(gapcDebugMenuEntrySpeedoUnitOptions) / sizeof(gapcDebugMenuEntrySpeedoUnitOptions[0]), eSpeedoUnitMPH);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[2], gapcDebugMenuEntryNames[2], gapcDebugMenuEntry3Options, sizeof(gapcDebugMenuEntry3Options) / sizeof(gapcDebugMenuEntry3Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[3], gapcDebugMenuEntryNames[3], gapcDebugMenuEntry4Options, sizeof(gapcDebugMenuEntry4Options) / sizeof(gapcDebugMenuEntry4Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[4], gapcDebugMenuEntryNames[4], gapcDebugMenuEntry5Options, sizeof(gapcDebugMenuEntry5Options) / sizeof(gapcDebugMenuEntry5Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[5], gapcDebugMenuEntryNames[5], gapcDebugMenuNoOptions, sizeof(gapcDebugMenuNoOptions) / sizeof(gapcDebugMenuNoOptions[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[6], gapcDebugMenuEntryNames[6], gapcDebugMenuNoOptions, sizeof(gapcDebugMenuNoOptions) / sizeof(gapcDebugMenuNoOptions[0]), 0);
    }

    CB4DebugBackgroundComponent__Prepare(&gDebugMenuComponents->mBackground);
    CB4DebugVSelectOptionComponent__Prepare(&gDebugMenuComponents->mVSelectOption, gaDebugMenuEntries, sizeof(gaDebugMenuEntries) / sizeof(gaDebugMenuEntries[0]));
}
