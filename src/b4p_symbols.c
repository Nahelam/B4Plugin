#include "b4p_common.h"
#include "b4p_debug_menu.h"
#include "b4p_debug_menu_options.h"
#include "b4p_flow.h"
#include "b4p_input.h"
#include "b4p_sound.h"

#define SYM(type, name, addr) type name = (type)addr

// --------------------------------
//    b4p_debug_menu
// --------------------------------

SYM(void*, gDebugMenu, 0x1C10EF0);
SYM(CB4DebugMenuComponents*, gDebugMenuComponents, 0x1C10EA0);
SYM(void*, gDebugMenuPageManager, 0x1C10EE0);

SYM(CB4VoidMethod_t, CB4DebugMenuPageBase__Prepare, 0x186DF0);
SYM(CB4VoidMethod_t, CB4DebugDebugMenuPage__Prepare, 0x186768);
SYM(CB4VoidMethod_t, CB4DebugDebugMenuPage__Update, 0x1869F0);
SYM(CB4DebugBackgroundComponent__Prepare_t, CB4DebugBackgroundComponent__Prepare, 0x187078);
SYM(CB4DebugVSelectEntry__Prepare_t, CB4DebugVSelectEntry__Prepare, 0x1877A8);
SYM(CB4DebugVSelectOptionComponent__Prepare_t, CB4DebugVSelectOptionComponent__Prepare, 0x1877E0);
SYM(CB4MenuSelectionData__Select_t, CB4MenuSelectionData__SelectNext, 0x183F18);
SYM(CB4MenuSelectionData__Select_t, CB4MenuSelectionData__SelectPrev, 0x183EF8);

// --------------------------------
//    b4p_debug_menu_options
// --------------------------------

SYM(CB4GraphicsManager*, gGraphicsManager, 0x1BFE760);
SYM(void*, gAptManager, 0x1C0A2D0);
SYM(void*, gGame, 0x4F3300);

SYM(CB4GraphicsManager__SetVideoMode_t, CB4GraphicsManager__SetVideoMode, 0x14C338);
SYM(CB4VoidMethod_t, CB4AptManager__SetScreenSettings, 0x17D370);
SYM(CB4Game__SetFrontendFrameRate_t, CB4Game__SetFrontendFrameRate, 0x1125C0);

// --------------------------------
//    b4p_flow
// --------------------------------

SYM(CB4MenuFlowManager*, gMenuFlowManager, 0x1C11160);
SYM(uint64_t*, kB4MainMenuStateID, 0x4B80F8);
SYM(uint64_t*, kB4DebugMenuStateID, 0x4B6860);

SYM(CGtFSM__GetStateFromID_t, CGtFSM__GetStateFromID, 0x2FED60);
SYM(CGtFSM__StateEnter_t, CGtFSM__StateEnter, 0x2FEDE0);
SYM(CGtFSM__StateLeave_t, CGtFSM__StateLeave, 0x2FEDA0);
SYM(CB4MenuFlowManager__ApplyEvent_t, CB4MenuFlowManager__ApplyEvent, 0x187AF0);
SYM(CB4State__Action_t, CB4MainMenuState__Action, 0x1943A8);
SYM(CB4State__Action_t, CB4DebugDebugMenuState__Action, 0x192248);
SYM(CB4MainMenuState__InitiateConfirm_t, CB4MainMenuState__InitiateConfirm, 0x194540);
SYM(CB4DebugMenuPageManager__ImmediateLeadOut_t, CB4DebugMenuPageManager__ImmediateLeadOut, 0x185DC8);

// --------------------------------
//    b4p_input
// --------------------------------

SYM(void*, gInputManager, 0x4F33C0);

SYM(CB4ControllerMapping__GetPadControl_t, CB4ControllerMapping__GetPadControl, 0x113000);
SYM(CB4InputManager__GetMenuButton_t, CB4InputManager__GetMenuButton, 0x105C48);

// --------------------------------
//    b4p_sound
// --------------------------------

SYM(void*, gHUDSoundManager, 0x1C891B0);

SYM(CB4HUDSoundManager__HandleFESound_t, CB4HUDSoundManager__HandleFESound, 0x235DC8);
