#ifndef B4P_DEBUG_MENU_PAGE_BASE_H_INCLUDED
#define B4P_DEBUG_MENU_PAGE_BASE_H_INCLUDED

#include <stdint.h>
#include "b4p_vtable.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugMenuPageBase CB4DebugMenuPageBase;
typedef struct CB4DebugMenuPageBase__vtable CB4DebugMenuPageBase__vtable;

// Take advantage of these 8 unused bytes to add a custom vtable (ApplyVSelectOption)
struct CB4DebugMenuPageBase__vtable { // 0x18
    __vtbl_ptr_type ApplyVSelectOption; // uint8_t __pad0[8];
    __vtbl_ptr_type Update;
    __vtbl_ptr_type Release;
};

struct CB4DebugMenuPageBase { // 0x4
    CB4DebugMenuPageBase__vtable* __vtable; // __vtbl_ptr_type*
};

// --------------------------------
//    Declarations
// --------------------------------

typedef void (*ApplyVSelectOption_t)(CB4DebugMenuPageBase *_this);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4DebugMenuPageBase__Prepare_t)(CB4DebugMenuPageBase* _this);

extern CB4DebugMenuPageBase__Prepare_t CB4DebugMenuPageBase__Prepare;

#endif
