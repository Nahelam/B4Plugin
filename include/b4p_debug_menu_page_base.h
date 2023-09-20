#ifndef B4P_DEBUG_MENU_PAGE_BASE_H_INCLUDED
#define B4P_DEBUG_MENU_PAGE_BASE_H_INCLUDED

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugMenuPageBase CB4DebugMenuPageBase;

struct CB4DebugMenuPageBase { // 0x4
    void* __vtable; // __vtbl_ptr_type*
};

// --------------------------------
//    Declarations
// --------------------------------


// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4DebugMenuPageBase__Prepare_t)(CB4DebugMenuPageBase* _this);

extern CB4DebugMenuPageBase__Prepare_t CB4DebugMenuPageBase__Prepare;

#endif
