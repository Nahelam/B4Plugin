#include "pcsx2f_api.h"
#include "log.h"
#include "injector.h"
#include "b4_states.h"
#include "b4_debug_menu.h"

int CompatibleCRCList[] = { 0x28B66C81, 0xD224D348 };
char OSDText[OSDStringNum][OSDStringSize] = { {1} };

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
