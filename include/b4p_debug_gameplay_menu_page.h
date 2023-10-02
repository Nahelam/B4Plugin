#ifndef B4P_DEBUG_GAMEPLAY_MENU_PAGE_H_INCLUDED
#define B4P_DEBUG_GAMEPLAY_MENU_PAGE_H_INCLUDED

#include "b4p_debug_menu_page_base.h"
#include "b4p_debug_vselect_option_component.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugGameplayMenuPage CB4DebugGameplayMenuPage;
typedef struct CB4DebugGameplayMenuPage__vtable CB4DebugGameplayMenuPage__vtable;

struct CB4DebugGameplayMenuPage { // 0x28
    CB4DebugMenuPageBase mBase;
};

struct CB4DebugGameplayMenuPage__vtable { // 0x18
    CB4DebugMenuPageBase__vtable __vtable;
};

// --------------------------------
//    Declarations
// --------------------------------

extern CB4DebugGameplayMenuPage gDebugGameplayMenuPage;
extern CB4DebugGameplayMenuPage__vtable gDebugGameplayMenuPage__vtable;

extern bool gbDebugGameplayMenuCameraSpeedShake;
extern bool gbDebugGameplayMenuOfflineCarAirControl;

void CB4DebugGameplayMenuPage__Prepare(CB4DebugGameplayMenuPage* _this);
void CB4DebugGameplayMenuPage__Update(CB4DebugGameplayMenuPage* _this);
void CB4DebugGameplayMenuPage__Release(CB4DebugGameplayMenuPage* _this);
void CB4DebugGameplayMenuPage__InitSelections(CB4DebugGameplayMenuPage* _this);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------


#endif
