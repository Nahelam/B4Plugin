#include "pcsx2f_api.h"
#include "log.h"
#include "symbols.h"
#include "injector.h"
#include "hooks.h"
#include "menu.h"

int CompatibleCRCList[] = { 0x28B66C81, 0xD224D348 };
char OSDText[OSDStringNum][OSDStringSize] = { {1} };

void CGtFSM__StateEnterHook(CGtFSM* _this, void* lpOldState, void* lpUserData)
{
    logger.WriteF("State enter: %016llX", _this->mpState->mID);
    CGtFSM__StateEnter(_this, lpOldState, lpUserData);
}

void CB4MainMenuState__ActionHook(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData)
{
    /*
    if (leAction != eGtStateActionUpdate)
    {
        logger.WriteF("Action: %08X, ActionData: %08X, UserData: %08X", leAction, lpActionData, lpUserData);
    }
    */
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

void ChangeState(void* _this, uint64_t lDestinationState, void* lpUserData)
{
    CGtState* lpNewState;
    CGtState* lpOldState;
    
    lpNewState = CGtFSM__GetStateFromID(&gMenuFlowManager->mFSM, lDestinationState);
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
    // CB4DebugDebugMenuState__Action(_this, leAction, lpOwner, lpActionData, lpUserData);
}

bool UpdateSelection(CB4DebugVSelectOptionComponent* _this)
{
    bool lbUpdate;
    bool lbSelectDone;
    bool lbUp;
    bool lbDown;
    bool lbLeft;
    bool lbRight;
    CB4MenuSelectionData* lpSelectionData;
    
    lbUpdate = false;
    lbUp = CB4InputManager__GetMenuButton(gInputManager, eButtonUp, -1);
    lbDown = CB4InputManager__GetMenuButton(gInputManager, eButtonDown, -1);
    lbLeft = CB4InputManager__GetMenuButton(gInputManager, eButtonLeft, -1);
    lbRight = CB4InputManager__GetMenuButton(gInputManager, eButtonRight, -1);

    if (lbUp || lbDown || lbLeft || lbRight)
    {
        lbUpdate = true;
        
        if (lbUp || lbDown)
        {
            lpSelectionData = &_this->mSelectionData;
            if (lbUp)
            {
                lbSelectDone = CB4MenuSelectionData__SelectPrev(lpSelectionData);
            }
            else if (lbDown)
            {
                lbSelectDone = CB4MenuSelectionData__SelectNext(lpSelectionData);
            }
            CB4HUDSoundManager__HandleFESound(gHUDSoundManager, eSoundFEVertMove);
        }
        else if (lbLeft || lbRight)
        {
            lpSelectionData = &_this->mpEntries[(_this->mSelectionData).mu16CurrentItem].mSelectionData;
            if (lbLeft)
            {
                lbSelectDone = CB4MenuSelectionData__SelectPrev(lpSelectionData);
            }
            else if (lbRight)
            {
                lbSelectDone = CB4MenuSelectionData__SelectNext(lpSelectionData);
            }

            // Don't play the option select sound if there are no options
            if (lpSelectionData->mu16NumItems > 1)
            {
                CB4HUDSoundManager__HandleFESound(gHUDSoundManager, eSoundFEOptionsHoriMove);
            }
        }
        
        // Circular selection
        if (!lbSelectDone)
        {
            if (lbUp || lbLeft)
            {
                lpSelectionData->mu16CurrentItem = lpSelectionData->mu16NumItems - 1;
            }
            else if (lbDown || lbRight)
            {
                lpSelectionData->mu16CurrentItem = 0;
            }
        }
    }
    
    return lbUpdate;
}

void VideoModeConfirm(CB4DebugVSelectOptionComponent* _this)
{
    EB4VideoMode leSelectedVideoMode;
    
    leSelectedVideoMode = gaDebugMenuEntries[0].mSelectionData.mu16CurrentItem;
    if (leSelectedVideoMode != gGraphicsManager->meCurrentVideoMode)
    {
        CB4GraphicsManager__SetVideoMode(gGraphicsManager, leSelectedVideoMode);
        CB4AptManager__SetScreenSettings(gAptManager);
        CB4Game__SetFrontendFrameRate(gGame, true);
    }
}

void CB4DebugVSelectOptionComponent__UpdateHook(CB4DebugVSelectOptionComponent* _this)
{
    if (UpdateSelection(_this))
    {
        return;
    }
    
    if (CB4InputManager__GetMenuButton(gInputManager, eButtonBack, -1))
    {
        CB4DebugMenuPageManager__ImmediateLeadOut(gDebugMenuPageManager, eMenuFlowEventMenuPageBack);
    }
    
    else if (CB4InputManager__GetMenuButton(gInputManager, eButtonConfirm, -1))
    {
        switch (gDebugMenuComponents->mVSelectOption.mSelectionData.mu16CurrentItem)
        {
            case 0: // Video Mode
                CB4HUDSoundManager__HandleFESound(gHUDSoundManager, eSoundFESelect);
                VideoModeConfirm(_this);
                break;
        }
    }
}

void CB4DebugDebugMenuPage__PrepareHook(void* _this)
{
    static bool lbEntriesPrepared = false;

    CB4DebugMenuPageBase__Prepare(_this);
    
    if (!lbEntriesPrepared)
    {
        lbEntriesPrepared = true;
        //CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[0], gapcDebugMenuEntryNames[0], gapcDebugMenuEntry1Options, sizeof(gapcDebugMenuEntry1Options) / sizeof(gapcDebugMenuEntry1Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[0], gapcDebugMenuEntryNames[0], gapcDebugMenuEntryVideoModeOptions, 3, gGraphicsManager->meCurrentVideoMode);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[1], gapcDebugMenuEntryNames[1], gapcDebugMenuEntry2Options, sizeof(gapcDebugMenuEntry2Options) / sizeof(gapcDebugMenuEntry2Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[2], gapcDebugMenuEntryNames[2], gapcDebugMenuEntry3Options, sizeof(gapcDebugMenuEntry3Options) / sizeof(gapcDebugMenuEntry3Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[3], gapcDebugMenuEntryNames[3], gapcDebugMenuEntry4Options, sizeof(gapcDebugMenuEntry4Options) / sizeof(gapcDebugMenuEntry4Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[4], gapcDebugMenuEntryNames[4], gapcDebugMenuEntry5Options, sizeof(gapcDebugMenuEntry5Options) / sizeof(gapcDebugMenuEntry5Options[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[5], gapcDebugMenuEntryNames[5], gapcDebugMenuNoOptions, sizeof(gapcDebugMenuNoOptions) / sizeof(gapcDebugMenuNoOptions[0]), 0);
        CB4DebugVSelectEntry__Prepare(&gaDebugMenuEntries[6], gapcDebugMenuEntryNames[6], gapcDebugMenuNoOptions, sizeof(gapcDebugMenuNoOptions) / sizeof(gapcDebugMenuNoOptions[0]), 0);
    }
    
    CB4DebugBackgroundComponent__Prepare(&gDebugMenuComponents->mBackground);
    CB4DebugVSelectOptionComponent__Prepare(&gDebugMenuComponents->mVSelectOption, gaDebugMenuEntries, sizeof(gaDebugMenuEntries) / sizeof(gaDebugMenuEntries[0]));
}

void init()
{
    logger.SetBuffer(OSDText, sizeof(OSDText) / sizeof(OSDText[0]), sizeof(OSDText[0]));
    logger.Write("B4Plugin loaded");
    injector.WriteMemory32(0x49F894, &CGtFSM__StateEnterHook);
    injector.WriteMemory32(0x49FB9C, &CB4MainMenuState__ActionHook);
    injector.WriteMemory32(0x49FADC, &CB4DebugDebugMenuState__ActionHook);
    injector.WriteMemory32(0x49F84C, &CB4DebugVSelectOptionComponent__UpdateHook);
    // injector.MakeJAL(0x187A78, ); render string justified call for menu options
}

int main()
{
    return 0;
}
