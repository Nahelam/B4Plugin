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

void CB4HUDSpeedo__PrepareHook(void* _this, CGtV2d* lPos, CGtV2d* lHandle, float lrHeight, EStyle leStyle, uint16_t* lpString) // broken
{
    if (gleDebugHUDMenuSpeedometerUnit == eSpeedoUnitKPH)
    {
        lpString = (uint32_t)lpString - 8; // MPH and KPH strings are contiguous (ou pas en fait)
    }
    CB4HUDText2dObject__Prepare(_this, lPos, lHandle, lrHeight, leStyle, lpString);
}

uint16_t* CB4HUDSpeedo__UpdateHook(uint16_t* lpTargetString, int32_t luValue, int32_t lnPrecision, ENumericFormat leFormat)
{
    float lrValue;
    
    lrValue = (float)luValue;
    if (gleDebugHUDMenuSpeedometerUnit == eSpeedoUnitMPH)
    {
        lrValue *= MPH_CONV_FACTOR;
    }
    else if (gleDebugHUDMenuSpeedometerUnit == eSpeedoUnitKPH)
    {
        lrValue *= KPH_CONV_FACTOR;
    }
    
    return CGtUnicode__PrintInt(lpTargetString, (int32_t)lrValue, lnPrecision, leFormat);
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
