#ifndef B4P_DEBUG_MENU_PAGE_BASE_H_INCLUDED
#define B4P_DEBUG_MENU_PAGE_BASE_H_INCLUDED

#include <stdint.h>
#include <stddef.h>
#include "b4p_vtable.h"

#define COUNT_OF(x) ((sizeof(x) / sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugMenuPageBase CB4DebugMenuPageBase;
typedef struct CB4DebugMenuPageBase__vtable CB4DebugMenuPageBase__vtable;

// Added "Prepare" and "ApplyVSelectOption" methods to the original vtable structure
struct CB4DebugMenuPageBase__vtable { // 0x20
    __vtbl_ptr_type Prepare; // uint8_t __pad0[8];
    __vtbl_ptr_type Update;
    __vtbl_ptr_type Release;
    __vtbl_ptr_type ApplyVSelectOption;
};

struct CB4DebugMenuPageBase { // 0x4
    CB4DebugMenuPageBase__vtable* __vtable; // __vtbl_ptr_type*
};

// --------------------------------
//    Declarations
// --------------------------------

typedef void (*CB4DebugMenuPageBase__ApplyVSelectOption_t)(CB4DebugMenuPageBase* _this);
typedef void (*CB4DebugMenuPageBase__Release_t)(CB4DebugMenuPageBase* _this);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*CB4DebugMenuPageBase__Prepare_t)(CB4DebugMenuPageBase* _this);

extern CB4DebugMenuPageBase__Prepare_t CB4DebugMenuPageBase__Prepare;

#endif
