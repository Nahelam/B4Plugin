#include "b4p_debug_menu.h"
#include "b4p_debug_menu_entries.h"
#include "b4p_debug_menu_options.h"
#include "b4p_flow.h"
#include "b4p_input.h"
#include "b4p_sound.h"

static EVSelectUpdateType UpdateSelection(CB4DebugVSelectOptionComponent* _this)
{
    EVSelectUpdateType leUpdateType;
    bool lbSelectDone;
    bool lbUp;
    bool lbDown;
    bool lbLeft;
    bool lbRight;
    CB4MenuSelectionData* lpSelectionData;
    
    leUpdateType = eVSelectUpdateTypeNone;
    lbUp = CB4InputManager__GetMenuButton(gInputManager, eButtonUp, -1);
    lbDown = CB4InputManager__GetMenuButton(gInputManager, eButtonDown, -1);
    lbLeft = CB4InputManager__GetMenuButton(gInputManager, eButtonLeft, -1);
    lbRight = CB4InputManager__GetMenuButton(gInputManager, eButtonRight, -1);

    if (lbUp || lbDown || lbLeft || lbRight)
    {   
        if (lbUp || lbDown)
        {
            leUpdateType = eVSelectUpdateTypeVertical;
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
            leUpdateType = eVSelectUpdateTypeHorizontal;
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
    
    return leUpdateType;
}

static void ApplyOption(CB4DebugVSelectOptionComponent* _this)
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

void CB4DebugVSelectOptionComponent__UpdateHook(CB4DebugVSelectOptionComponent* _this)
{
    EVSelectUpdateType leUpdateType;
    
    leUpdateType = UpdateSelection(_this);
    if (leUpdateType != eVSelectUpdateTypeNone)
    {
        if (leUpdateType == eVSelectUpdateTypeHorizontal)
        {
            ApplyOption(_this);
        }
        
        return;
    }
    
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

void CB4DebugDebugMenuPage__PrepareHook(void* _this)
{
    static bool lbEntriesPrepared = false;

    CB4DebugMenuPageBase__Prepare(_this);
    
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
