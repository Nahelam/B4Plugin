#include "b4p_hud.h"
#include "b4p_debug_hud_menu_page.h"
#include "b4p_other.h"

/*
void CB4HUDManager__PrepareNormalComponentsHook(CB4HUDManager* _this, EPlayerCarIndex lePlayer)
{
    switch (_this->meHUDType)
    {
        case eHUDTypeRace:
            CB4HUDSpeedo__Prepare(gHUDSpeedoComponent[lePlayer], lePlayer, eHUDAlignBottomRight, 1);
            CB4HUDPos__Prepare(gHUDPosComponent[lePlayer], lePlayer, eHUDAlignTopRight, 1, false, false);
            CB4HUDLap__Prepare(gHUDLapComponent[lePlayer], lePlayer, eHUDAlignTopLeft, 1, false);
            break;
    }
}
*/

void CB4HUDManager__RenderHook(CB4HUDManager* _this)
{
    if (gbDebugHUDMenuRenderHUD)
    {
        CB4HUDManager__Render(_this);
    }
}

void CB4HUDSpeedo__PrepareHook(void* _this, CGtV2d* lPos, CGtV2d* lHandle, float lrHeight, EStyle leStyle, uint16_t* lpString)
{
    if (gleDebugHUDMenuSpeedometerUnit == eSpeedoUnitKPH)
    {
        // lpString = CB4HUDComponent__mgapHUDStrings[13];
        asm ( // Using an asm hack here because lrHeight is stored in the f12 register thus lpString is in a4 but the compiler thinks it is in a5, idk how to fix this
            "move $a4, %0"
            :
            : "r" (CB4HUDComponent__mgapHUDStrings[13])
        );
    }
    CB4HUDText2dObject__Prepare(_this, lPos, lHandle, lrHeight, leStyle, lpString);
}

uint16_t* CB4HUDSpeedo__UpdateHook(uint16_t* lpTargetString, int32_t luValue, int32_t lnPrecision, ENumericFormat leFormat)
{
    float lrf0;

    asm (
        "swc1 $f0, %0"
        :
        : "m" (lrf0)
    );
    
    if (gleDebugHUDMenuSpeedometerUnit == eSpeedoUnitMPH)
    {
        lrf0 *= MPH_CONV_FACTOR;
    }
    else if (gleDebugHUDMenuSpeedometerUnit == eSpeedoUnitKPH)
    {
        lrf0 *= KPH_CONV_FACTOR;
    }
    
    return CGtUnicode__PrintInt(lpTargetString, (int32_t)lrf0, lnPrecision, leFormat);
}

bool CB4HUDRating__PrepareHook(void* _this, EPlayerCarIndex lePlayer, EHUDAlign leAlign, int32_t lxFlags)
{
    bool lbRet;
    
    lbRet = true;
    if (gbDebugHUDMenuRatingComponentEnabled)
    {
        lbRet = CB4HUDRating__Prepare(_this, lePlayer, leAlign, lxFlags);
    }
    return lbRet;
}

bool CB4HUDGameMode__PrepareHook(void* _this, EPlayerCarIndex lePlayer, EHUDAlign leAlign, int32_t lxFlags, uint16_t* lpString)
{
    bool lbRet;
    
    lbRet = true;
    if (gbDebugHUDMenuGameModeComponentEnabled)
    {
        lbRet = CB4HUDGameMode__Prepare(_this, lePlayer, leAlign, lxFlags, lpString);
    }
    return lbRet;
}
