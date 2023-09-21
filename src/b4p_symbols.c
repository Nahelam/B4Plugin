#include "b4p_debug_background_component.h"
#include "b4p_debug_original_menu_page.h"
#include "b4p_debug_menu_state.h"
#include "b4p_debug_menu_components.h"
#include "b4p_other.h"
#include "b4p_debug_menu_page_base.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_debug_menu_pages.h"
#include "b4p_debug_vselect_option_component.h"
#include "b4p_state.h"
#include "b4p_input.h"
#include "b4p_main_menu_state.h"
#include "b4p_menu_selection_data.h"
#include "b4p_menu_flow_manager.h"
#include "b4p_sound.h"

#define SYM(type, name, addr) type name = (type)addr

// ----------------------------------------------------------------
//    b4p_debug_background_component
// ----------------------------------------------------------------

SYM(CB4DebugBackgroundComponent__Prepare_t, CB4DebugBackgroundComponent__Prepare, 0x187078);

// ----------------------------------------------------------------
//    b4p_debug_original_menu_page
// ----------------------------------------------------------------

SYM(CB4DebugOriginalMenuPage__Prepare_t, CB4DebugOriginalMenuPage__Prepare, 0x186768);
SYM(CB4DebugOriginalMenuPage__Update_t, CB4DebugOriginalMenuPage__Update, 0x1869F0);

// ----------------------------------------------------------------
//    b4p_debug_menu_state
// ----------------------------------------------------------------

SYM(CB4DebugMenuState__Action_t, CB4DebugMenuState__Action, 0x192248);

// ----------------------------------------------------------------
//    b4p_debug_menu_components
// ----------------------------------------------------------------

SYM(CB4DebugMenuComponents*, gDebugMenuComponents, 0x1C10EA0);

// ----------------------------------------------------------------
//    b4p_debug_menu_page_base
// ----------------------------------------------------------------

SYM(CB4DebugMenuPageBase__Prepare_t, CB4DebugMenuPageBase__Prepare, 0x186DF0);

// ----------------------------------------------------------------
//    b4p_debug_menu_page_manager
// ----------------------------------------------------------------

SYM(CB4DebugMenuPageManager*, gDebugMenuPageManager, 0x1C10EE0);

SYM(CB4DebugMenuPageManager__ImmediateLeadOut_t, CB4DebugMenuPageManager__ImmediateLeadOut, 0x185DC8);

// ----------------------------------------------------------------
//    b4p_debug_menu_pages
// ----------------------------------------------------------------

SYM(CB4DebugMenuPages*, gDebugMenuPages, 0x1C10EF0);

SYM(CB4DebugMenuPages__Init_t, CB4DebugMenuPages__Init, 0x185FE8);

// ----------------------------------------------------------------
//    b4p_debug_vselect_component
// ----------------------------------------------------------------

SYM(CB4DebugVSelectComponent__Prepare_t, CB4DebugVSelectComponent__Prepare, 0x187580);
SYM(CB4DebugVSelectComponent__Update_t, CB4DebugVSelectComponent__Update, 0x1875C8);

// ----------------------------------------------------------------
//    b4p_debug_vselect_option_component
// ----------------------------------------------------------------

SYM(CB4DebugVSelectOptionComponent__Prepare_t, CB4DebugVSelectOptionComponent__Prepare, 0x1877E0);
SYM(CB4DebugVSelectOptionComponent__Update_t, CB4DebugVSelectOptionComponent__Update, 0x187828);
SYM(CB4DebugVSelectEntry__Prepare_t, CB4DebugVSelectEntry__Prepare, 0x1877A8);

// ----------------------------------------------------------------
//    b4p_input
// ----------------------------------------------------------------

SYM(void*, gInputManager, 0x4F33C0);

SYM(CB4ControllerMapping__GetPadControl_t, CB4ControllerMapping__GetPadControl, 0x113000);
SYM(CB4InputManager__GetMenuButton_t, CB4InputManager__GetMenuButton, 0x105C48);

// ----------------------------------------------------------------
//    b4p_main_menu_state
// ----------------------------------------------------------------

SYM(CB4MainMenuState__Action_t, CB4MainMenuState__Action, 0x1943A8);
SYM(CB4MainMenuState__InitiateConfirm_t, CB4MainMenuState__InitiateConfirm, 0x194540);

// ----------------------------------------------------------------
//    b4p_menu_flow_manager
// ----------------------------------------------------------------

SYM(CB4MenuFlowManager*, gMenuFlowManager, 0x1C11160);

SYM(CB4MenuFlowManager__ApplyEvent_t, CB4MenuFlowManager__ApplyEvent, 0x187AF0);

// ----------------------------------------------------------------
//    b4p_menu_selection_data
// ----------------------------------------------------------------

SYM(CB4MenuSelectionData__SelectNext_t, CB4MenuSelectionData__SelectNext, 0x183F18);
SYM(CB4MenuSelectionData__SelectPrev_t, CB4MenuSelectionData__SelectPrev, 0x183EF8);

// ----------------------------------------------------------------
//    b4p_other
// ----------------------------------------------------------------

SYM(CB4GraphicsManager*, gGraphicsManager, 0x1BFE760);
SYM(void*, gAptManager, 0x1C0A2D0);
SYM(void*, gGame, 0x4F3300);

SYM(CB4GraphicsManager__SetVideoMode_t, CB4GraphicsManager__SetVideoMode, 0x14C338);
SYM(CB4AptManager__SetScreenSettings_t, CB4AptManager__SetScreenSettings, 0x17D370);
SYM(CB4Game__SetFrontendFrameRate_t, CB4Game__SetFrontendFrameRate, 0x1125C0);

// ----------------------------------------------------------------
//    b4p_sound
// ----------------------------------------------------------------

SYM(void*, gHUDSoundManager, 0x1C891B0);

SYM(CB4HUDSoundManager__HandleFESound_t, CB4HUDSoundManager__HandleFESound, 0x235DC8);

// ----------------------------------------------------------------
//    b4p_state
// ----------------------------------------------------------------

SYM(uint64_t*, kB4MainMenuStateID, 0x4B80F8);
SYM(uint64_t*, kB4DebugMenuStateID, 0x4B6860);

SYM(CGtFSM__GetStateFromID_t, CGtFSM__GetStateFromID, 0x2FED60);
SYM(CGtFSM__StateEnter_t, CGtFSM__StateEnter, 0x2FEDE0);
SYM(CGtFSM__StateLeave_t, CGtFSM__StateLeave, 0x2FEDA0);
