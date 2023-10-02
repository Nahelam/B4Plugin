#include "log.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_debug_menu_state.h"
#include "b4p_debug_main_menu_page.h"
#include "b4p_debug_menu_components.h"
#include "b4p_debug_menu_pages.h"
#include "b4p_debug_vselect_option_component.h"
#include "b4p_menu_flow_manager.h"
#include "b4p_sound.h"
#include "b4p_other.h"

void CB4DebugMenuState__ActionHook(CB4DebugMenuState* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData)
{
    CB4DebugMenuPageBase* lpCurrentPage;
    CB4DebugMenuPageBase* lpDestinationPage;
    CB4DebugMenuPageBase__Prepare_t lpfPrepare;
    
    lpCurrentPage = gDebugMenuPageManager->mpCurrentPage;
    // lpUserData contains the original debug menu base address when we leave it (forward & back events)
    if (lpCurrentPage == &gDebugMenuPages->mDebugMenu.mBase || (CB4DebugMenuPageBase*)lpUserData == &gDebugMenuPages->mDebugMenu.mBase)
    {
        CB4DebugMenuState__Action(_this, leAction, lpOwner, lpActionData, lpUserData);
        if (lpCurrentPage == &gDebugMenuPages->mDebugMenu.mBase || (leAction == eGtStateActionEvent && (EB4MenuFlowEvents)lpActionData == eMenuFlowEventMenuPageForward))
        {
            return;
        }
    }
    
    if (leAction == eGtStateActionEnter)
    {
        CB4DebugMainMenuPage__Prepare(&gDebugMainMenuPage);
        CB4HUDSoundManager__HandleFESound(gHUDSoundManager, eSoundFELocked);
    }
    else if (leAction == eGtStateActionEvent)
    {
        switch ((EB4MenuFlowEvents)lpActionData)
        {
            case eMenuFlowEventMenuPageForward:
                if ((CB4DebugMenuPageBase*)lpUserData != &gDebugMainMenuPage.mBase) // When we are coming back from a sub menu with changes applied
                {
                    CB4DebugMainMenuPage__Prepare(&gDebugMainMenuPage);
                    CB4HUDSoundManager__HandleFESound(gHUDSoundManager, eSoundFESelect);
                }
                else
                {
                    lpDestinationPage = gapDebugMenuPagesBases[gDebugMenuComponents->mVSelect.mSelectionData.mu16CurrentItem + 1]; // Current entry + 1 because index 0 is main menu
                    lpfPrepare = (CB4DebugMenuPageBase__Prepare_t)lpDestinationPage->__vtable->Prepare.__pfn;
                    lpfPrepare(lpDestinationPage);
                    CB4HUDSoundManager__HandleFESound(gHUDSoundManager, 0x34);
                }
                break;

            case eMenuFlowEventMenuPageBack:
                if ((CB4DebugMenuPageBase*)lpUserData == &gDebugMainMenuPage.mBase)
                {
                    ChangeState(*kB4MainMenuStateID, kB4DebugMenuStateID);
                    CB4HUDSoundManager__HandleFESound(gHUDSoundManager, eSoundFELand);
                }
                else
                {
                    CB4DebugMainMenuPage__Prepare(&gDebugMainMenuPage);
                    CB4HUDSoundManager__HandleFESound(gHUDSoundManager, 0x36);
                }
                break;
        }
    }

/*
    if (leAction != eGtStateActionUpdate)
    {
        logger.WriteF("Action: %08X, ActionData: %08X, UserData: %08X", leAction, lpActionData, lpUserData);
    }
*/
}
