#include "log.h"
#include "b4p_flow.h"
#include "b4p_debug_menu.h"
#include "b4p_input.h"
#include "b4p_sound.h"

void ChangeState(void* _this, uint64_t lu64DestinationState, void* lpUserData)
{
    CGtState* lpNewState;
    CGtState* lpOldState;
    
    lpNewState = CGtFSM__GetStateFromID(&gMenuFlowManager->mFSM, lu64DestinationState);
    if (gMenuFlowManager->mFSM.mpState != lpNewState)
    {
        CGtFSM__StateLeave(&gMenuFlowManager->mFSM, lpNewState, lpUserData);
        lpOldState = gMenuFlowManager->mFSM.mpState;
        gMenuFlowManager->mFSM.mpState = lpNewState;
        if (gMenuFlowManager->mFSM.mpStateTimer != NULL)
        {
            gMenuFlowManager->mFSM.mrTimeStateEntered = gMenuFlowManager->mFSM.mpStateTimer->mrTime;
            if (lpNewState != NULL)
            {
                lpNewState->mrTimeStateEntered = gMenuFlowManager->mFSM.mpStateTimer->mrTime;
            }
        }
        CGtFSM__StateEnter(&gMenuFlowManager->mFSM, lpOldState, lpUserData);
    }
}

void CGtFSM__StateEnterHook(CGtFSM* _this, void* lpOldState, void* lpUserData)
{
    logger.WriteF("State enter: %016llX", _this->mpState->mID);
    CGtFSM__StateEnter(_this, lpOldState, lpUserData);
}

void CB4MainMenuState__ActionHook(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData)
{
    CB4MainMenuState__Action(_this, leAction, lpOwner, lpActionData, lpUserData);
    if ( leAction == eGtStateActionUpdate
         && CB4ControllerMapping__GetPadControl(gInputManager, eGtPS2DualShock_Control_Start, false, -1) > 0.0
         && CB4ControllerMapping__GetPadControl(gInputManager, eGtPS2DualShock_Control_Select, false, -1) > 0.0
         && CB4ControllerMapping__GetPadControl(gInputManager, eGtPS2DualShock_Control_Right_Shoulder_2, false, -1) > 0.0 
         && CB4ControllerMapping__GetPadControl(gInputManager, eGtPS2DualShock_Control_Left_Shoulder_2, false, -1) > 0.0 )
    {
        // 0x962C720DB0B4C738 = Debug menu state id
        CB4MainMenuState__InitiateConfirm(_this, *kB4DebugMenuStateID);
    }
}

void CB4DebugDebugMenuState__ActionHook(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData)
{
    if (leAction == eGtStateActionEnter)
    {
        CB4DebugDebugMenuPage__PrepareHook(gDebugMenu);
        CB4HUDSoundManager__HandleFESound(gHUDSoundManager, eSoundFELocked);
    }
    else if (leAction == eGtStateActionEvent && (EB4MenuFlowEvents)lpActionData == eMenuFlowEventMenuPageBack)
    {
        ChangeState(_this, *kB4MainMenuStateID, kB4DebugMenuStateID);
        CB4HUDSoundManager__HandleFESound(gHUDSoundManager, eSoundFELand);
    }
    
    if (leAction != eGtStateActionUpdate)
    {
        logger.WriteF("Action: %08X, ActionData: %08X, UserData: %08X", leAction, lpActionData, lpUserData);
    }
}