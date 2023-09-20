#include "log.h"
#include "injector.h"
#include "mips.h"
#include "b4p_debug_debug_menu_state.h"
#include "b4p_debug_debug_menu_page.h"
#include "b4p_debug_menu_components.h"
#include "b4p_debug_menu_pages.h"
#include "b4p_debug_vselect_option_component.h"
#include "b4p_menu_flow_manager.h"
#include "b4p_state.h"
#include "b4p_sound.h"
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

static void ApplyVSelectOptionChange()
{
    uint16_t u16CurrentEntry;
    uint16_t u16CurrentEntryOption;

    u16CurrentEntry = gDebugMenuComponents->mVSelectOption.mSelectionData.mu16CurrentItem;
    u16CurrentEntryOption = gaDebugMenuEntries[u16CurrentEntry].mSelectionData.mu16CurrentItem;

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

void CB4DebugDebugMenuState__ActionHook(CB4DebugDebugMenuState* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData)
{
    if (leAction == eGtStateActionEnter)
    {
        CB4DebugDebugMenuPage__PrepareHook(&gDebugMenuPages->mDebugMenu);
        CB4HUDSoundManager__HandleFESound(gHUDSoundManager, eSoundFELocked);
    }
    else if (leAction == eGtStateActionEvent)
    {
        switch ((EB4MenuFlowEvents)lpActionData)
        {
            case eMenuFlowEventMenuPageBack:
                ChangeState(*kB4MainMenuStateID, kB4DebugMenuStateID);
                CB4HUDSoundManager__HandleFESound(gHUDSoundManager, eSoundFELand);
                break;

            case eMenuFlowEventMenuPageDebugButtonEvent:
                if ((EVSelectOptionUpdateType)lpUserData == eVSelectOptionUpdateTypeHorizontal)
                {
                    ApplyVSelectOptionChange();
                }
                break;
        }
    }

    if (leAction != eGtStateActionUpdate)
    {
        logger.WriteF("Action: %08X, ActionData: %08X, UserData: %08X", leAction, lpActionData, lpUserData);
    }
}
