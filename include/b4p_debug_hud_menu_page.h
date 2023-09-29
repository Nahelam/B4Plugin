#ifndef B4P_DEBUG_HUD_MENU_PAGE_H_INCLUDED
#define B4P_DEBUG_HUD_MENU_PAGE_H_INCLUDED

#include "b4p_debug_menu_page_base.h"
#include "b4p_debug_vselect_option_component.h"

// --------------------------------
//    Enums
// --------------------------------

typedef enum {
    eSpeedoUnitMPH = 0,
    eSpeedoUnitKPH = 1
} ESpeedoUnit;

// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugHUDMenuPage CB4DebugHUDMenuPage;
typedef struct CB4DebugHUDMenuPage__vtable CB4DebugHUDMenuPage__vtable;

struct CB4DebugHUDMenuPage { // 0x28
    CB4DebugMenuPageBase mBase;
};

struct CB4DebugHUDMenuPage__vtable { // 0x18
    CB4DebugMenuPageBase__vtable __vtable;
};

// --------------------------------
//    Declarations
// --------------------------------

extern CB4DebugHUDMenuPage gDebugHUDMenuPage;
extern CB4DebugHUDMenuPage__vtable gDebugHUDMenuPage__vtable;

extern bool gbDebugHUDMenuRenderHUD;
extern bool gbDebugHUDMenuRatingComponentEnabled;
extern bool gbDebugHUDMenuGameModeComponentEnabled;
extern ESpeedoUnit gleDebugHUDMenuSpeedometerUnit;

void CB4DebugHUDMenuPage__Prepare(CB4DebugHUDMenuPage* _this);
void CB4DebugHUDMenuPage__Update(CB4DebugHUDMenuPage* _this);
void CB4DebugHUDMenuPage__Release(CB4DebugHUDMenuPage* _this);
void CB4DebugHUDMenuPage__InitSelections(CB4DebugHUDMenuPage* _this);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------


#endif
