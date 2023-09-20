#ifndef B4P_DEBUG_VSELECT_OPTION_COMPONENT_H_INCLUDED
#define B4P_DEBUG_VSELECT_OPTION_COMPONENT_H_INCLUDED

#include <stdint.h>
#include "b4p_debug_menu_component_base.h"
#include "b4p_menu_selection_data.h"

// --------------------------------
//    Enums
// --------------------------------

typedef enum {
    eVSelectOptionUpdateTypeNone = 0,
    eVSelectOptionUpdateTypeVertical = 1,
    eVSelectOptionUpdateTypeHorizontal = 2
} EVSelectOptionUpdateType;

// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugVSelectOptionComponent CB4DebugVSelectOptionComponent;
typedef struct CB4DebugVSelectEntry CB4DebugVSelectEntry;

struct CB4DebugVSelectEntry { // 0xC
    uint8_t* mpcEntryName; // GtUTF8*
    uint8_t** mppcOptionsList; // GtUTF8**
    CB4MenuSelectionData mSelectionData;
};

struct CB4DebugVSelectOptionComponent { // 0x14
    CB4DebugMenuComponentBase mBase;
    CB4DebugVSelectEntry* mpEntries;
    CB4MenuSelectionData mSelectionData;
};

// --------------------------------
//    Declarations
// --------------------------------

void CB4DebugVSelectOptionComponent__UpdateHook(CB4DebugVSelectOptionComponent* _this);

// --------------------------------
//    B4 Variables
// --------------------------------


// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4DebugVSelectOptionComponent__Prepare_t)(CB4DebugVSelectOptionComponent* _this, CB4DebugVSelectEntry* lpEntries, int lnNumEntries);
typedef void (*const CB4DebugVSelectOptionComponent__Update_t)(CB4DebugVSelectOptionComponent* _this);
typedef void (*const CB4DebugVSelectEntry__Prepare_t)(CB4DebugVSelectEntry* _this, const char* lpcEntryName, const char** lppcOptionsList, int lnNumOptions, int lnInitialOptionSelection);

extern CB4DebugVSelectOptionComponent__Prepare_t CB4DebugVSelectOptionComponent__Prepare;
extern CB4DebugVSelectOptionComponent__Update_t CB4DebugVSelectOptionComponent__Update;
extern CB4DebugVSelectEntry__Prepare_t CB4DebugVSelectEntry__Prepare;

#endif
