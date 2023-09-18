#ifndef B4P_DEBUG_MENU_H_INCLUDED
#define B4P_DEBUG_MENU_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "b4p_common.h"

// --------------------------------
//    Enums
// --------------------------------

typedef enum {
    eVSelectUpdateTypeNone = 0,
    eVSelectUpdateTypeVertical = 1,
    eVSelectUpdateTypeHorizontal = 2
} EVSelectUpdateType;

// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugMenuComponentBase CB4DebugMenuComponentBase;
typedef struct CB4DebugVSelectComponent CB4DebugVSelectComponent;
typedef struct CB4DebugVSelectOptionComponent CB4DebugVSelectOptionComponent;
typedef struct CB4DebugBackgroundComponent CB4DebugBackgroundComponent;
typedef struct CB4DebugOnlineCarSelectComponent CB4DebugOnlineCarSelectComponent;
typedef struct CB4DebugMenuComponents CB4DebugMenuComponents;
typedef struct CB4DebugVSelectEntry CB4DebugVSelectEntry;
typedef struct CB4MenuSelectionData CB4MenuSelectionData;

struct CB4DebugMenuComponentBase { // 0xC
    CB4DebugMenuComponentBase *mpNext;
    bool mbIsActive;
    uint8_t __pad0[3];
    void* __vtable; // __vtbl_ptr_type*
};

struct CB4MenuSelectionData { // 0x4
    uint16_t mu16CurrentItem; // RwUInt16
    uint16_t mu16NumItems; // RwUInt16
};

struct CB4DebugVSelectEntry { // 0xC
    uint8_t* mpcEntryName; // GtUTF8*
    uint8_t** mppcOptionsList; // GtUTF8**
    CB4MenuSelectionData mSelectionData;
};

struct CB4DebugVSelectComponent { // 0x14
    CB4DebugMenuComponentBase mBase;
    CB4MenuSelectionData mSelectionData;
    uint8_t** mppcEntriesList; // GtUTF8**
};

struct CB4DebugVSelectOptionComponent { // 0x14
    CB4DebugMenuComponentBase mBase;
    CB4DebugVSelectEntry* mpEntries;
    CB4MenuSelectionData mSelectionData;
};

struct CB4DebugBackgroundComponent { // 0xC
    CB4DebugMenuComponentBase mBase;
};

struct CB4DebugOnlineCarSelectComponent { // 0xC
    CB4DebugMenuComponentBase mBase;
};

struct CB4DebugMenuComponents { // 0x40
    CB4DebugBackgroundComponent mBackground;
    CB4DebugVSelectComponent mVSelect;
    CB4DebugVSelectOptionComponent mVSelectOption;
    CB4DebugOnlineCarSelectComponent mOnlineCarSelect;
};

// --------------------------------
//    Declarations
// --------------------------------

void CB4DebugDebugMenuPage__PrepareHook(void* _this);
void CB4DebugVSelectOptionComponent__UpdateHook(CB4DebugVSelectOptionComponent* _this);

// --------------------------------
//    B4 Variables
// --------------------------------

extern void* gDebugMenu;
extern CB4DebugMenuComponents* gDebugMenuComponents;
extern void* gDebugMenuPageManager;

// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4DebugBackgroundComponent__Prepare_t)(CB4DebugBackgroundComponent* _this);
typedef void (*const CB4DebugVSelectEntry__Prepare_t)(CB4DebugVSelectEntry* _this, const char* lpcEntryName, const char** lppcOptionsList, int lnNumOptions, int lnInitialOptionSelection);
typedef void (*const CB4DebugVSelectOptionComponent__Prepare_t)(CB4DebugVSelectOptionComponent* _this, CB4DebugVSelectEntry* lpEntries, int lnNumEntries);
typedef bool (*const CB4MenuSelectionData__Select_t)(CB4MenuSelectionData* _this);

extern CB4VoidMethod_t CB4DebugMenuPageBase__Prepare;
extern CB4VoidMethod_t CB4DebugDebugMenuPage__Prepare;
extern CB4VoidMethod_t CB4DebugDebugMenuPage__Update;
extern CB4DebugBackgroundComponent__Prepare_t CB4DebugBackgroundComponent__Prepare;
extern CB4DebugVSelectEntry__Prepare_t CB4DebugVSelectEntry__Prepare;
extern CB4DebugVSelectOptionComponent__Prepare_t CB4DebugVSelectOptionComponent__Prepare;
extern CB4MenuSelectionData__Select_t CB4MenuSelectionData__SelectNext;
extern CB4MenuSelectionData__Select_t CB4MenuSelectionData__SelectPrev;

#endif
