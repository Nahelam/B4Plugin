#ifndef B4P_DEBUG_TEST_MENU_PAGE_H_INCLUDED
#define B4P_DEBUG_TEST_MENU_PAGE_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "b4p_debug_menu_page_base.h"
#include "b4p_debug_vselect_option_component.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugTestMenuPage CB4DebugTestMenuPage;
typedef struct CB4DebugTestMenuPage__vtable CB4DebugTestMenuPage__vtable;

struct CB4DebugTestMenuPage { // 0x28
    CB4DebugMenuPageBase mBase;
};

struct CB4DebugTestMenuPage__vtable { // 0x18
    CB4DebugMenuPageBase__vtable __vtable;
};

// --------------------------------
//    Declarations
// --------------------------------

extern CB4DebugTestMenuPage gDebugTestMenuPage;
extern CB4DebugTestMenuPage__vtable gDebugTestMenuPage__vtable;

void CB4DebugTestMenuPage__Prepare(CB4DebugTestMenuPage* _this);
void CB4DebugTestMenuPage__Update(CB4DebugTestMenuPage* _this);
void CB4DebugTestMenuPage__Release(CB4DebugTestMenuPage* _this);
void CB4DebugTestMenuPage__ApplyVSelectOption(CB4DebugTestMenuPage* _this);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------


#endif
