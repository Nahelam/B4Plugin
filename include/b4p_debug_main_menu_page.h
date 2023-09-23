#ifndef B4P_DEBUG_MAIN_MENU_PAGE_H_INCLUDED
#define B4P_DEBUG_MAIN_MENU_PAGE_H_INCLUDED

#include "b4p_debug_menu_page_base.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugMainMenuPage CB4DebugMainMenuPage;
typedef struct CB4DebugMainMenuPage__vtable CB4DebugMainMenuPage__vtable;

struct CB4DebugMainMenuPage { // 0x28
    CB4DebugMenuPageBase mBase;
};

struct CB4DebugMainMenuPage__vtable { // 0x18
    CB4DebugMenuPageBase__vtable __vtable;
};

// --------------------------------
//    Declarations
// --------------------------------

extern CB4DebugMainMenuPage gDebugMainMenuPage;
extern CB4DebugMainMenuPage__vtable gDebugMainMenuPage__vtable;

void CB4DebugMainMenuPage__Prepare(CB4DebugMainMenuPage* _this);
void CB4DebugMainMenuPage__Update(CB4DebugMainMenuPage* _this);
void CB4DebugMainMenuPage__Release(CB4DebugMainMenuPage* _this);
void CB4DebugMainMenuPage__ApplyVSelectOption(CB4DebugMainMenuPage* _this);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------


#endif
