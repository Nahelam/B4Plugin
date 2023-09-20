#ifndef B4P_MENU_SELECTION_DATA_H_INCLUDED
#define B4P_MENU_SELECTION_DATA_H_INCLUDED

#include <stdint.h>

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4MenuSelectionData CB4MenuSelectionData;

struct CB4MenuSelectionData { // 0x4
    uint16_t mu16CurrentItem; // RwUInt16
    uint16_t mu16NumItems; // RwUInt16
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

typedef bool (*const CB4MenuSelectionData__SelectNext_t)(CB4MenuSelectionData* _this);
typedef bool (*const CB4MenuSelectionData__SelectPrev_t)(CB4MenuSelectionData* _this);

extern CB4MenuSelectionData__SelectNext_t CB4MenuSelectionData__SelectNext;
extern CB4MenuSelectionData__SelectPrev_t CB4MenuSelectionData__SelectPrev;

#endif
