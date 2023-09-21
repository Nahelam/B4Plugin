#include "pcsx2f_api.h"
#include "log.h"
#include "injector.h"
#include "b4p_debug_menu_pages.h"
#include "b4p_state.h"
#include "b4p_main_menu_state.h"
#include "b4p_debug_menu_state.h"
#include "b4p_debug_vselect_component.h"
#include "b4p_debug_vselect_option_component.h"

// Now create our own page instead of modifying the current debug one ?

int CompatibleCRCList[] = { 0x28B66C81, 0xD224D348 };
char OSDText[OSDStringNum][OSDStringSize] = { {1} };

void init()
{
    logger.SetBuffer(OSDText, sizeof(OSDText) / sizeof(OSDText[0]), sizeof(OSDText[0]));
    logger.Write("B4Plugin loaded");
    injector.WriteMemory32(0x47F820, (uintptr_t)&CB4DebugMenuPages__InitHook);
    injector.WriteMemory32(0x49F894, (uintptr_t)&CGtFSM__StateEnterHook);
    injector.WriteMemory32(0x49FB9C, (uintptr_t)&CB4MainMenuState__ActionHook);
    injector.WriteMemory32(0x49FADC, (uintptr_t)&CB4DebugMenuState__ActionHook);
    injector.WriteMemory32(0x49F82C, (uintptr_t)&CB4DebugVSelectComponent__UpdateHook);
    injector.WriteMemory32(0x49F84C, (uintptr_t)&CB4DebugVSelectOptionComponent__UpdateHook);
    // injector.MakeJAL(0x187A78, ); render string justified call for menu options
}

int main()
{
    return 0;
}
