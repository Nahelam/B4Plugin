#include "log.h"
#include "b4p_state.h"
#include "b4p_menu_flow_manager.h"
#include "b4p_input.h"
#include "b4p_sound.h"

void CGtFSM__StateEnterHook(CGtFSM* _this, void* lpOldState, void* lpUserData)
{
    logger.WriteF("State enter: %016llX", _this->mpState->mID);
    CGtFSM__StateEnter(_this, lpOldState, lpUserData);
}

void ChangeState(uint64_t lu64DestinationState, void* lpUserData)
{
    CGtFSM* lpFSM;
    CGtState* lpNewState;
    CGtState* lpOldState;

    lpFSM = &gMenuFlowManager->mFSM;
    lpNewState = CGtFSM__GetStateFromID(lpFSM, lu64DestinationState);
    if (lpFSM->mpState != lpNewState)
    {
        CGtFSM__StateLeave(lpFSM, lpNewState, lpUserData);
        lpOldState = lpFSM->mpState;
        lpFSM->mpState = lpNewState;
        if (lpFSM->mpStateTimer != NULL)
        {
            lpFSM->mrTimeStateEntered = lpFSM->mpStateTimer->mrTime;
            if (lpNewState != NULL)
            {
                lpNewState->mrTimeStateEntered = lpFSM->mpStateTimer->mrTime;
            }
        }
        CGtFSM__StateEnter(lpFSM, lpOldState, lpUserData);
    }
}
