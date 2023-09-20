#ifndef B4P_DEBUG_VSELECT_COMPONENT_H_INCLUDED
#define B4P_DEBUG_VSELECT_COMPONENT_H_INCLUDED

#include <stdint.h>
#include "b4p_debug_menu_component_base.h"
#include "b4p_menu_selection_data.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugVSelectComponent CB4DebugVSelectComponent;

struct CB4DebugVSelectComponent { // 0x14
    CB4DebugMenuComponentBase mBase;
    CB4MenuSelectionData mSelectionData;
    uint8_t** mppcEntriesList; // GtUTF8**
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
