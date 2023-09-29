#include "b4p_debug_vselect_option_component.h"
#include "b4p_menu_selection_data.h"
#include "b4p_menu_flow_manager.h"
#include "b4p_input.h"
#include "b4p_sound.h"

void CB4DebugVSelectOptionComponent__UpdateHook(CB4DebugVSelectOptionComponent* _this)
{
    bool lbSelectDone;
    bool lbUp;
    bool lbDown;
    bool lbLeft;
    bool lbRight;
    CB4MenuSelectionData* lpSelectionData;

    lbUp = CB4InputManager__GetMenuButton(gInputManager, eButtonUp, -1);
    lbDown = CB4InputManager__GetMenuButton(gInputManager, eButtonDown, -1);
    lbLeft = CB4InputManager__GetMenuButton(gInputManager, eButtonLeft, -1);
    lbRight = CB4InputManager__GetMenuButton(gInputManager, eButtonRight, -1);

    if (lbUp || lbDown || lbLeft || lbRight)
    {
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
            CB4HUDSoundManager__HandleFESound(gHUDSoundManager, 0x31);
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
                CB4HUDSoundManager__HandleFESound(gHUDSoundManager, 0x35);
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
}
