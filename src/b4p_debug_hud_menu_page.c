#include "injector.h"
#include "mips.h"
#include "b4p_debug_hud_menu_page.h"
#include "b4p_debug_hud_menu_options.h"
#include "b4p_debug_menu_common_options.h"
#include "b4p_debug_menu_page_manager.h"
#include "b4p_debug_menu_page_base.h"
#include "b4p_debug_menu_components.h"
#include "b4p_debug_background_component.h"
#include "b4p_debug_vselect_option_component.h"
#include "b4p_input.h"
#include "b4p_other.h"

bool gbDebugHUDMenuRenderHUD;
bool gbDebugHUDMenuRatingComponentEnabled;
bool gbDebugHUDMenuGameModeComponentEnabled;
ESpeedoUnit gleDebugHUDMenuSpeedometerUnit;

static const char* kapcDebugHUDMenuEntryNames[] = {
    "Render HUD",
    "Rating Component",
    "Game Mode Component",
    "Speedometer Unit",
    "Apply Changes"
};

static CB4DebugVSelectEntry kaDebugHUDMenuEntries[COUNT_OF(kapcDebugHUDMenuEntryNames)];
static uint16_t kau16DebugHUDMenuSelections[COUNT_OF(kapcDebugHUDMenuEntryNames) - 1];

static void ApplyVideoMode(EB4VideoMode leSelectedVideoMode)
{
    if (leSelectedVideoMode != gGraphicsManager->meCurrentVideoMode)
    {
        CB4GraphicsManager__SetVideoMode(gGraphicsManager, leSelectedVideoMode);
        CB4AptManager__SetScreenSettings(gAptManager);
        CB4Game__SetFrontendFrameRate(gGame, true);
    }
}

static void CB4DebugHUDMenuPage__InitSelections(CB4DebugHUDMenuPage* _this)
{
    gbDebugHUDMenuRenderHUD = true;
    gbDebugHUDMenuRatingComponentEnabled = true;
    gbDebugHUDMenuGameModeComponentEnabled = true;
    gleDebugHUDMenuSpeedometerUnit = eSpeedoUnitMPH;
}

static void CB4DebugHUDMenuPage__ApplySelections(CB4DebugHUDMenuPage* _this)
{
    gbDebugHUDMenuRenderHUD = (kaDebugHUDMenuEntries[0].mSelectionData.mu16CurrentItem == 0);
    gbDebugHUDMenuRatingComponentEnabled = (kaDebugHUDMenuEntries[1].mSelectionData.mu16CurrentItem == 0);
    gbDebugHUDMenuGameModeComponentEnabled = (kaDebugHUDMenuEntries[2].mSelectionData.mu16CurrentItem == 0);
    gleDebugHUDMenuSpeedometerUnit = (ESpeedoUnit)(kaDebugHUDMenuEntries[3].mSelectionData.mu16CurrentItem);
}

static void CB4DebugHUDMenuPage__RestoreSelections(CB4DebugHUDMenuPage* _this)
{
    int32_t i;
    for (i = 0; i < COUNT_OF(kapcDebugHUDMenuEntryNames) - 1; i++)
    {
        kaDebugHUDMenuEntries[i].mSelectionData.mu16CurrentItem = kau16DebugHUDMenuSelections[i];
    }
}

void CB4DebugHUDMenuPage__Update(CB4DebugHUDMenuPage* _this)
{
    if (CB4InputManager__GetMenuButton(gInputManager, eButtonBack, -1))
    {
        CB4DebugHUDMenuPage__RestoreSelections(_this);
        CB4DebugMenuPageManager__ImmediateLeadOut2(gDebugMenuPageManager, eMenuFlowEventMenuPageBack);
    }

    else if ( CB4InputManager__GetMenuButton(gInputManager, eButtonConfirm, -1) &&
              gDebugMenuComponents->mVSelectOption.mSelectionData.mu16CurrentItem == (COUNT_OF(kapcDebugHUDMenuEntryNames) - 1))
    {
        CB4DebugHUDMenuPage__ApplySelections(_this);
        CB4DebugMenuPageManager__ImmediateLeadOut2(gDebugMenuPageManager, eMenuFlowEventMenuPageForward);
    }
}

void CB4DebugHUDMenuPage__Release(CB4DebugHUDMenuPage* _this)
{

}

void CB4DebugHUDMenuPage__Prepare(CB4DebugHUDMenuPage* _this)
{
    static bool lbEntriesPrepared = false;
    int32_t i;

    CB4DebugMenuPageBase__Prepare(&_this->mBase);

    if (!lbEntriesPrepared)
    {
        lbEntriesPrepared = true;
        CB4DebugHUDMenuPage__InitSelections(_this);
        CB4DebugVSelectEntry__Prepare(&kaDebugHUDMenuEntries[0], kapcDebugHUDMenuEntryNames[0], gapcDebugMenuEntryYesNoOptions, COUNT_OF(gapcDebugMenuEntryYesNoOptions), 0);
        CB4DebugVSelectEntry__Prepare(&kaDebugHUDMenuEntries[1], kapcDebugHUDMenuEntryNames[1], gapcDebugMenuEntryOnOffOptions, COUNT_OF(gapcDebugMenuEntryOnOffOptions), 0);
        CB4DebugVSelectEntry__Prepare(&kaDebugHUDMenuEntries[2], kapcDebugHUDMenuEntryNames[2], gapcDebugMenuEntryOnOffOptions, COUNT_OF(gapcDebugMenuEntryOnOffOptions), 0);
        CB4DebugVSelectEntry__Prepare(&kaDebugHUDMenuEntries[3], kapcDebugHUDMenuEntryNames[3], kapcDebugMenuEntrySpeedoUnitOptions, COUNT_OF(kapcDebugMenuEntrySpeedoUnitOptions), 0);
        CB4DebugVSelectEntry__Prepare(&kaDebugHUDMenuEntries[4], kapcDebugHUDMenuEntryNames[4], gapcDebugMenuNoOptions, COUNT_OF(gapcDebugMenuNoOptions), 0);
    }
    
    for (i = 0; i < COUNT_OF(kapcDebugHUDMenuEntryNames) - 1; i++)
    {
        kau16DebugHUDMenuSelections[i] = kaDebugHUDMenuEntries[i].mSelectionData.mu16CurrentItem;
    }

    CB4DebugBackgroundComponent__Prepare(&gDebugMenuComponents->mBackground);
    CB4DebugVSelectOptionComponent__Prepare(&gDebugMenuComponents->mVSelectOption, kaDebugHUDMenuEntries, COUNT_OF(kaDebugHUDMenuEntries));
}
