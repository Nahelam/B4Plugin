#include "injector.h"
#include "mips.h"
#include "b4p_debug_gameplay_menu_page.h"
#include "b4p_debug_menu_common_options.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_debug_menu_components.h"
#include "b4p_debug_background_component.h"
#include "b4p_input.h"
#include "b4p_other.h"

bool gbDebugGameplayMenuCameraSpeedShake;
bool gbDebugGameplayMenuOfflineCarAirControl;

static const char* kapcDebugGameplayMenuEntryNames[] = {
    "Camera Speed Shake",
    "Offline Car Air Control",
    "Apply Changes"
};

static CB4DebugVSelectEntry kaDebugGameplayMenuEntries[COUNT_OF(kapcDebugGameplayMenuEntryNames)];
static uint16_t kau16DebugGameplayMenuSelections[COUNT_OF(kapcDebugGameplayMenuEntryNames) - 1];

static void CB4DebugGameplayMenuPage__ApplySelections(CB4DebugGameplayMenuPage* _this)
{
    gbDebugGameplayMenuCameraSpeedShake = (kaDebugGameplayMenuEntries[0].mSelectionData.mu16CurrentItem == 0);
    gbDebugGameplayMenuOfflineCarAirControl = (kaDebugGameplayMenuEntries[1].mSelectionData.mu16CurrentItem == 0);
}

static void CB4DebugGameplayMenuPage__SaveSelections(CB4DebugGameplayMenuPage* _this)
{
    int32_t i;

    for (i = 0; i < COUNT_OF(kapcDebugGameplayMenuEntryNames) - 1; i++)
    {
        kau16DebugGameplayMenuSelections[i] = kaDebugGameplayMenuEntries[i].mSelectionData.mu16CurrentItem;
    }
}

static void CB4DebugGameplayMenuPage__RestoreSelections(CB4DebugGameplayMenuPage* _this)
{
    int32_t i;

    for (i = 0; i < COUNT_OF(kapcDebugGameplayMenuEntryNames) - 1; i++)
    {
        kaDebugGameplayMenuEntries[i].mSelectionData.mu16CurrentItem = kau16DebugGameplayMenuSelections[i];
    }
}

void CB4DebugGameplayMenuPage__InitSelections(CB4DebugGameplayMenuPage* _this)
{
    gbDebugGameplayMenuCameraSpeedShake = true;
    gbDebugGameplayMenuOfflineCarAirControl = false;
}

void CB4DebugGameplayMenuPage__Update(CB4DebugGameplayMenuPage* _this)
{
    if (CB4InputManager__GetMenuButton(gInputManager, eButtonBack, -1))
    {
        CB4DebugGameplayMenuPage__RestoreSelections(_this);
        CB4DebugMenuPageManager__ImmediateLeadOut2(gDebugMenuPageManager, eMenuFlowEventMenuPageBack);
    }

    else if ( CB4InputManager__GetMenuButton(gInputManager, eButtonConfirm, -1) &&
              gDebugMenuComponents->mVSelectOption.mSelectionData.mu16CurrentItem == (COUNT_OF(kapcDebugGameplayMenuEntryNames) - 1))
    {
        CB4DebugGameplayMenuPage__ApplySelections(_this);
        CB4DebugMenuPageManager__ImmediateLeadOut2(gDebugMenuPageManager, eMenuFlowEventMenuPageForward);
    }
}

void CB4DebugGameplayMenuPage__Release(CB4DebugGameplayMenuPage* _this)
{

}

void CB4DebugGameplayMenuPage__Prepare(CB4DebugGameplayMenuPage* _this)
{
    static bool lbEntriesPrepared = false;

    CB4DebugMenuPageBase__Prepare(&_this->mBase);

    if (!lbEntriesPrepared)
    {
        lbEntriesPrepared = true;
        CB4DebugVSelectEntry__Prepare(&kaDebugGameplayMenuEntries[0], kapcDebugGameplayMenuEntryNames[0], gapcDebugMenuEntryOnOffOptions, COUNT_OF(gapcDebugMenuEntryOnOffOptions), 0);
        CB4DebugVSelectEntry__Prepare(&kaDebugGameplayMenuEntries[1], kapcDebugGameplayMenuEntryNames[1], gapcDebugMenuEntryOnOffOptions, COUNT_OF(gapcDebugMenuEntryOnOffOptions), 1);
        CB4DebugVSelectEntry__Prepare(&kaDebugGameplayMenuEntries[2], kapcDebugGameplayMenuEntryNames[2], gapcDebugMenuNoOptions, COUNT_OF(gapcDebugMenuNoOptions), 0);
    }
    
    CB4DebugGameplayMenuPage__SaveSelections(_this);
    CB4DebugBackgroundComponent__Prepare(&gDebugMenuComponents->mBackground);
    CB4DebugVSelectOptionComponent__Prepare(&gDebugMenuComponents->mVSelectOption, kaDebugGameplayMenuEntries, COUNT_OF(kaDebugGameplayMenuEntries));
}
