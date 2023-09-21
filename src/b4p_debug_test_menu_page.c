#include "injector.h"
#include "mips.h"
#include "b4p_debug_test_menu_page.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_debug_menu_page_base.h"
#include "b4p_debug_test_menu_entries.h"
#include "b4p_debug_menu_components.h"
#include "b4p_debug_background_component.h"
#include "b4p_debug_vselect_option_component.h"
#include "b4p_input.h"
#include "b4p_other.h"

static void ApplyVideoMode(EB4VideoMode leSelectedVideoMode)
{
    if (leSelectedVideoMode != gGraphicsManager->meCurrentVideoMode)
    {
        CB4GraphicsManager__SetVideoMode(gGraphicsManager, leSelectedVideoMode);
        CB4AptManager__SetScreenSettings(gAptManager);
        CB4Game__SetFrontendFrameRate(gGame, true);
    }
}

static void ApplySpeedoUnit(ESpeedoUnit leSelectedSpeedoUnit)
{
    uint32_t luMIPSInstr;

    if (leSelectedSpeedoUnit == eSpeedoUnitKPH)
    {
        luMIPSInstr = daddu(v0, zero, zero);
        injector.WriteMemory32(0x1765E8, luMIPSInstr);
        injector.WriteMemory32(0x1767DC, luMIPSInstr);
    }
    else if (leSelectedSpeedoUnit == eSpeedoUnitMPH)
    {
        luMIPSInstr = sltiu(v0, v0, 2);
        injector.WriteMemory32(0x1765E8, luMIPSInstr);
        injector.WriteMemory32(0x1767DC, luMIPSInstr);
    }
}

void CB4DebugTestMenuPage__ApplyVSelectOption(CB4DebugTestMenuPage* _this)
{
    uint16_t u16CurrentEntry;
    uint16_t u16CurrentEntryOption;
    
    u16CurrentEntry = gDebugMenuComponents->mVSelectOption.mSelectionData.mu16CurrentItem;
    u16CurrentEntryOption = gDebugMenuComponents->mVSelectOption.mpEntries[u16CurrentEntry].mSelectionData.mu16CurrentItem;

    switch (u16CurrentEntry)
    {
        case 0:
            ApplyVideoMode(u16CurrentEntryOption);
            break;
        case 1:
            ApplySpeedoUnit(u16CurrentEntryOption);
            break;
    }
}

void CB4DebugTestMenuPage__Update(CB4DebugTestMenuPage* _this)
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

void CB4DebugTestMenuPage__Release(CB4DebugTestMenuPage* _this)
{

}

void CB4DebugTestMenuPage__Prepare(CB4DebugTestMenuPage* _this)
{
    static bool lbEntriesPrepared = false;

    CB4DebugMenuPageBase__Prepare(&_this->mBase);

    if (!lbEntriesPrepared)
    {
        lbEntriesPrepared = true;
        CB4DebugVSelectEntry__Prepare(&gaDebugTestMenuEntries[0], gapcDebugMenuEntryNames[0], gapcDebugMenuEntryVideoModeOptions, sizeof(gapcDebugMenuEntryVideoModeOptions) / sizeof(gapcDebugMenuEntryVideoModeOptions[0]), gGraphicsManager->meCurrentVideoMode);
        CB4DebugVSelectEntry__Prepare(&gaDebugTestMenuEntries[1], gapcDebugMenuEntryNames[1], gapcDebugMenuEntrySpeedoUnitOptions, sizeof(gapcDebugMenuEntrySpeedoUnitOptions) / sizeof(gapcDebugMenuEntrySpeedoUnitOptions[0]), eSpeedoUnitMPH);
        CB4DebugVSelectEntry__Prepare(&gaDebugTestMenuEntries[2], gapcDebugMenuEntryNames[2], gapcDebugMenuEntry3Options, sizeof(gapcDebugMenuEntry3Options) / sizeof(gapcDebugMenuEntry3Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugTestMenuEntries[3], gapcDebugMenuEntryNames[3], gapcDebugMenuEntry4Options, sizeof(gapcDebugMenuEntry4Options) / sizeof(gapcDebugMenuEntry4Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugTestMenuEntries[4], gapcDebugMenuEntryNames[4], gapcDebugMenuEntry5Options, sizeof(gapcDebugMenuEntry5Options) / sizeof(gapcDebugMenuEntry5Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugTestMenuEntries[5], gapcDebugMenuEntryNames[5], gapcDebugMenuNoOptions, sizeof(gapcDebugMenuNoOptions) / sizeof(gapcDebugMenuNoOptions[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugTestMenuEntries[6], gapcDebugMenuEntryNames[6], gapcDebugMenuNoOptions, sizeof(gapcDebugMenuNoOptions) / sizeof(gapcDebugMenuNoOptions[0]), 0);
    }

    CB4DebugBackgroundComponent__Prepare(&gDebugMenuComponents->mBackground);
    CB4DebugVSelectOptionComponent__Prepare(&gDebugMenuComponents->mVSelectOption, gaDebugTestMenuEntries, sizeof(gaDebugTestMenuEntries) / sizeof(gaDebugTestMenuEntries[0]));
}
