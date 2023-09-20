#include "b4p_main_menu_state.h"
#include "b4p_state.h"
#include "b4p_input.h"

void CB4MainMenuState__ActionHook(CB4MainMenuState* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData)
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
