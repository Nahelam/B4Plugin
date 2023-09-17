#ifndef B4_DEBUG_MENU_H_INCLUDED
#define B4_DEBUG_MENU_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "b4_states.h"

typedef enum {
    eVSelectUpdateTypeNone = 0,
    eVSelectUpdateTypeVertical = 1,
    eVSelectUpdateTypeHorizontal = 2
} EVSelectUpdateType;

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

void CB4DebugDebugMenuPage__PrepareHook(void* _this);
void CB4DebugVSelectOptionComponent__UpdateHook(CB4DebugVSelectOptionComponent* _this);

extern void* gDebugMenu;
extern CB4DebugMenuComponents* gDebugMenuComponents;
extern void* gDebugMenuPageManager;

extern void (*CB4DebugMenuPageBase__Prepare)(void* _this);
extern void (*CB4DebugDebugMenuPage__Prepare)(void* _this);
extern void (*CB4DebugDebugMenuPage__Update)(void* _this);
extern void (*CB4DebugBackgroundComponent__Prepare)(CB4DebugBackgroundComponent* _this);
extern void (*CB4DebugMenuPageManager__ImmediateLeadOut)(void* _this, EB4MenuFlowEvents leEvent);
extern void (*CB4DebugVSelectEntry__Prepare)(CB4DebugVSelectEntry* _this, char* lpcEntryName, char** lppcOptionsList, int lnNumOptions, int lnInitialOptionSelection);
extern void (*CB4DebugVSelectOptionComponent__Prepare)(CB4DebugVSelectOptionComponent* _this, CB4DebugVSelectEntry* lpEntries, int lnNumEntries);
extern bool (*CB4MenuSelectionData__SelectNext)(CB4MenuSelectionData* _this);
extern bool (*CB4MenuSelectionData__SelectPrev)(CB4MenuSelectionData* _this);

#endif
