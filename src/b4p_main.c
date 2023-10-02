#include <stdint.h>
#include "pcsx2f_api.h"
#include "log.h"
#include "injector.h"
#include "mips.h"
#include "b4p_debug_menu_pages.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_hud.h"
#include "b4p_other.h"
#include "b4p_state.h"
#include "b4p_main_menu_state.h"
#include "b4p_debug_original_menu_page.h"
#include "b4p_debug_menu_state.h"
#include "b4p_debug_vselect_component.h"
#include "b4p_debug_vselect_option_component.h"

#define UPPER16(x) (uint16_t)((x >> 16) & 0xFFFF)
#define LOWER16(x) (uint16_t)(x & 0xFFFF)

int CompatibleCRCList[] = { 0x28B66C81, 0xD224D348 };
char OSDText[OSDStringNum][OSDStringSize] = { {1} };

void init()
{
    logger.SetBuffer(OSDText, sizeof(OSDText) / sizeof(OSDText[0]), sizeof(OSDText[0]));
    logger.Write("B4Plugin loaded");
    
    // Menus/States
    injector.WriteMemory32(0x47F820, (uintptr_t)&CB4DebugMenuPages__InitHook);
    // injector.WriteMemory32(0x49F894, (uintptr_t)&CGtFSM__StateEnterHook);
    injector.WriteMemory32(0x49FB9C, (uintptr_t)&CB4MainMenuState__ActionHook);
    injector.WriteMemory32(0x49FADC, (uintptr_t)&CB4DebugMenuState__ActionHook);
    injector.WriteMemory32(0x49F82C, (uintptr_t)&CB4DebugVSelectComponent__UpdateHook);
    injector.WriteMemory32(0x49F84C, (uintptr_t)&CB4DebugVSelectOptionComponent__UpdateHook);
    injector.WriteMemory32(0x49F76C, (uintptr_t)&CB4DebugOriginalMenuPage__UpdateHook);
    injector.MakeJAL(0x186CC8, (uintptr_t)&CB4DebugMenuPageManager__ImmediateLeadOut2); // Make the original debug menu use ImmediateLeadOut2 to catch the forward event
    
    // Gameplay
    injector.WriteMemory32(0x20A4E4, lui(v0, UPPER16((uintptr_t)&gCarAirControl)));
    injector.WriteMemory32(0x20A4EC, lbu(a1, v0, LOWER16((uintptr_t)&gCarAirControl))); // Using positive offset for lbu right now, but if the lower 16 bits of the address are > 0x7FFF, a negative offset must be used and the upper 16 bits would require a +1
    injector.MakeJAL(0x104144, (uintptr_t)&CGtFramerateManager__PrepareHook);
    injector.MakeJAL(0x273764, (uintptr_t)&CB4CameraBehaviour__ApplySpeedBasedShakeHook);
    injector.MakeJAL(0x27A508, (uintptr_t)&CB4CameraBehaviour__ApplySpeedBasedShakeHook);
    
    // HUD
    // I could use gGraphicsManager.mbDrawHUD instead but I prefer making 100% that sure it will not be turned back on by the game
    injector.MakeJAL(0x10DDEC, (uintptr_t)&CB4HUDManager__RenderHook);
    injector.MakeJAL(0x10DE80, (uintptr_t)&CB4HUDManager__RenderHook);
    injector.MakeJAL(0x10E6FC, (uintptr_t)&CB4HUDManager__RenderHook);
    injector.MakeJAL(0x10E748, (uintptr_t)&CB4HUDManager__RenderHook);
    injector.MakeJAL(0x110D68, (uintptr_t)&CB4HUDManager__RenderHook);
    
    injector.MakeNOPWithSize(0x176824, 12); // NOP the game speedo calculation
    injector.MakeJAL(0x176654, (uintptr_t)&CB4HUDSpeedo__PrepareHook); // Handle the speedo string
    injector.MakeJAL(0x17683C, (uintptr_t)&CB4HUDSpeedo__UpdateHook); // Handle the speedo calculation
    
    injector.MakeJAL(0x16B8E8, (uintptr_t)&CB4HUDRating__PrepareHook);
    injector.MakeJAL(0x16B904, (uintptr_t)&CB4HUDRating__PrepareHook);
    
    injector.MakeJAL(0x1694C0, (uintptr_t)&CB4HUDGameMode__PrepareHook);
    injector.MakeJAL(0x169510, (uintptr_t)&CB4HUDGameMode__PrepareHook);
    
    // injector.MakeJAL(0x16AC9C, (uintptr_t)&CB4HUDManager__PrepareNormalComponentsHook);

    // Other
    // injector.MakeJAL(0x187A78, ); render string justified call for menu options
}

int main()
{
    return 0;
}
