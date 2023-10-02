#include "b4p_other.h"
#include "b4p_debug_gameplay_menu_page.h"

bool gCarAirControl;

void CGtFramerateManager__PrepareHook(void* _this)
{
    gCarAirControl = (gNetworkManager->mbIsOnline || gbDebugGameplayMenuOfflineCarAirControl);
    CGtFramerateManager__Prepare(_this);
}

void CB4CameraBehaviour__ApplySpeedBasedShakeHook(void* _this, void* lpRaceCarPhysics, float lrShakeScale)
{
    if (gbDebugGameplayMenuCameraSpeedShake)
    {
        CB4CameraBehaviour__ApplySpeedBasedShake(_this, lpRaceCarPhysics, lrShakeScale);
    }
}
