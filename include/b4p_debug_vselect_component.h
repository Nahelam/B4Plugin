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

void CB4DebugVSelectComponent__UpdateHook(CB4DebugVSelectComponent* _this);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4DebugVSelectComponent__Prepare_t)(CB4DebugVSelectComponent* _this, const char** lppcEntriesList, int lnNumEntries);
typedef void (*const CB4DebugVSelectComponent__Update_t)(CB4DebugVSelectComponent* _this);

extern CB4DebugVSelectComponent__Prepare_t CB4DebugVSelectComponent__Prepare;
extern CB4DebugVSelectComponent__Update_t CB4DebugVSelectComponent__Update;

#endif
