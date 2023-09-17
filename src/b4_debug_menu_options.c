#include "b4_debug_menu_options.h"
#include "mips.h"
#include "injector.h"

// ================================================================

CB4GraphicsManager* gGraphicsManager = 0x1BFE760;
void* gAptManager = 0x1C0A2D0;
void* gGame = 0x4F3300;

void (*CB4GraphicsManager__SetVideoMode)(CB4GraphicsManager* _this, EB4VideoMode leVideoMode) = 0x14C338;
void (*CB4AptManager__SetScreenSettings)(void* _this) = 0x17D370;
void (*CB4Game__SetFrontendFrameRate)(void* _this, bool lbSetFrontendFrameRate) = 0x1125C0;

// ================================================================

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
