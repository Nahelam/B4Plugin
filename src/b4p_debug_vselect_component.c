#include "b4p_debug_vselect_component.h"
#include "b4p_menu_selection_data.h"
#include "b4p_input.h"
#include "b4p_sound.h"

void CB4DebugVSelectComponent__UpdateHook(CB4DebugVSelectComponent* _this)
{
    bool lbSelectDone;
    bool lbUp;
    bool lbDown;
    CB4MenuSelectionData* lpSelectionData;

    lbUp = CB4InputManager__GetMenuButton(gInputManager, eButtonUp, -1);
    lbDown = CB4InputManager__GetMenuButton(gInputManager, eButtonDown, -1);

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

        // Circular selection
        if (!lbSelectDone)
        {
            if (lbUp)
            {
                lpSelectionData->mu16CurrentItem = lpSelectionData->mu16NumItems - 1;
            }
            else if (lbDown)
            {
                lpSelectionData->mu16CurrentItem = 0;
            }
        }
    }
}
