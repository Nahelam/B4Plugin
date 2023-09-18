#include "b4p_debug_menu_options.h"
#include "mips.h"
#include "injector.h"

void ApplyVideoMode(EB4VideoMode leSelectedVideoMode)
{
    if (leSelectedVideoMode != gGraphicsManager->meCurrentVideoMode)
    {
        CB4GraphicsManager__SetVideoMode(gGraphicsManager, leSelectedVideoMode);
        CB4AptManager__SetScreenSettings(gAptManager);
        CB4Game__SetFrontendFrameRate(gGame, true);
    }
}

void ApplySpeedoUnit(ESpeedoUnit leSelectedSpeedoUnit)
{
    uint32_t luMIPSInstr;
    
    if (leSelectedSpeedoUnit == eSpeedoUnitKPH)
    {
        luMIPSInstr = daddu(v0, zero, zero);
        injector.WriteMemory32(0x1765E8, luMIPSInstr);
        injector.WriteMemory32(0x1767DC, luMIPSInstr);
    }
    else if (leSelectedSpeedoUnit == eSpeedoUnitMPH)
    {
        luMIPSInstr = sltiu(v0, v0, 2);
        injector.WriteMemory32(0x1765E8, luMIPSInstr);
        injector.WriteMemory32(0x1767DC, luMIPSInstr);
    }
}
