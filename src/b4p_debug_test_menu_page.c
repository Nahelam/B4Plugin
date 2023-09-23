#include "injector.h"
#include "mips.h"
#include "b4p_debug_test_menu_page.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_debug_menu_page_base.h"
#include "b4p_debug_test_menu_options.h"
#include "b4p_debug_menu_components.h"
#include "b4p_debug_background_component.h"
#include "b4p_debug_vselect_option_component.h"
#include "b4p_input.h"
#include "b4p_other.h"

static const char* kapcDebugTestMenuEntryNames[] = {
    "Video Mode",
    "Speedometer Unit",
    "Test Entry 3",
    "Test Entry 4",
    "Test Entry 5",
    "Test Entry 6 (no options)",
    "Test Entry 7 (no options)"
};

static CB4DebugVSelectEntry kaDebugTestMenuEntries[COUNT_OF(kapcDebugTestMenuEntryNames)];

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
        CB4DebugMenuPageManager__ImmediateLeadOut2(gDebugMenuPageManager, eMenuFlowEventMenuPageBack);
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
        CB4DebugVSelectEntry__Prepare(&kaDebugTestMenuEntries[0], kapcDebugTestMenuEntryNames[0], kapcDebugTestMenuEntryVideoModeOptions, COUNT_OF(kapcDebugTestMenuEntryVideoModeOptions), gGraphicsManager->meCurrentVideoMode);
        CB4DebugVSelectEntry__Prepare(&kaDebugTestMenuEntries[1], kapcDebugTestMenuEntryNames[1], kapcDebugTestMenuEntrySpeedoUnitOptions, COUNT_OF(kapcDebugTestMenuEntrySpeedoUnitOptions), eSpeedoUnitMPH);
        CB4DebugVSelectEntry__Prepare(&kaDebugTestMenuEntries[2], kapcDebugTestMenuEntryNames[2], kapcDebugTestMenuEntry3Options, COUNT_OF(kapcDebugTestMenuEntry3Options), 0);
        CB4DebugVSelectEntry__Prepare(&kaDebugTestMenuEntries[3], kapcDebugTestMenuEntryNames[3], kapcDebugTestMenuEntry4Options, COUNT_OF(kapcDebugTestMenuEntry4Options), 0);
        CB4DebugVSelectEntry__Prepare(&kaDebugTestMenuEntries[4], kapcDebugTestMenuEntryNames[4], kapcDebugTestMenuEntry5Options, COUNT_OF(kapcDebugTestMenuEntry5Options), 0);
        CB4DebugVSelectEntry__Prepare(&kaDebugTestMenuEntries[5], kapcDebugTestMenuEntryNames[5], kapcDebugTestMenuNoOptions, COUNT_OF(kapcDebugTestMenuNoOptions), 0);
        CB4DebugVSelectEntry__Prepare(&kaDebugTestMenuEntries[6], kapcDebugTestMenuEntryNames[6], kapcDebugTestMenuNoOptions, COUNT_OF(kapcDebugTestMenuNoOptions), 0);
    }

    CB4DebugBackgroundComponent__Prepare(&gDebugMenuComponents->mBackground);
    CB4DebugVSelectOptionComponent__Prepare(&gDebugMenuComponents->mVSelectOption, kaDebugTestMenuEntries, COUNT_OF(kaDebugTestMenuEntries));
}
