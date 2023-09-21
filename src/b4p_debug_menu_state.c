#include "log.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_debug_menu_state.h"
#include "b4p_debug_test_menu_page.h"
#include "b4p_debug_menu_components.h"
#include "b4p_debug_menu_pages.h"
#include "b4p_debug_vselect_option_component.h"
#include "b4p_menu_flow_manager.h"
#include "b4p_state.h"
#include "b4p_sound.h"
#include "b4p_other.h"

void CB4DebugMenuState__ActionHook(CB4DebugMenuState* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData)
{
    CB4DebugMenuPageBase* lpCurrentPage;
    ApplyVSelectOption_t lpfnApplyVSelectOption;
    
    if (leAction == eGtStateActionEnter)
    {
        CB4DebugTestMenuPage__Prepare(&gDebugTestMenuPage);
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
                    lpCurrentPage = gDebugMenuPageManager->mpCurrentPage;
                    lpfnApplyVSelectOption = (ApplyVSelectOption_t)(lpCurrentPage->__vtable->ApplyVSelectOption.__pfn);
                    if (lpfnApplyVSelectOption)
                    {
                        lpfnApplyVSelectOption(lpCurrentPage);
                    }
                }
                break;
        }
    }

    if (leAction != eGtStateActionUpdate)
    {
        logger.WriteF("Action: %08X, ActionData: %08X, UserData: %08X", leAction, lpActionData, lpUserData);
    }
}
