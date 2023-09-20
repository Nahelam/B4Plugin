#ifndef B4P_DEBUG_MENU_COMPONENT_BASE_H_INCLUDED
#define B4P_DEBUG_MENU_COMPONENT_BASE_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugMenuComponentBase CB4DebugMenuComponentBase;

struct CB4DebugMenuComponentBase { // 0xC
    CB4DebugMenuComponentBase *mpNext;
    bool mbIsActive;
    uint8_t __pad0[3];
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


#endif
