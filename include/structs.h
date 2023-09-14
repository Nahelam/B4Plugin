#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdint.h>
#include "enums.h"

typedef struct CGtV4d CGtV4d;
typedef struct CGtState CGtState;
typedef struct CGtTimer CGtTimer;
typedef struct CGtFSM CGtFSM;
typedef struct CB4MenuFlowManager CB4MenuFlowManager;
typedef struct CB4DebugMenuComponentBase CB4DebugMenuComponentBase;
typedef struct CB4DebugVSelectComponent CB4DebugVSelectComponent;
typedef struct CB4DebugVSelectOptionComponent CB4DebugVSelectOptionComponent;
typedef struct CB4DebugBackgroundComponent CB4DebugBackgroundComponent;
typedef struct CB4DebugOnlineCarSelectComponent CB4DebugOnlineCarSelectComponent;
typedef struct CB4DebugMenuComponents CB4DebugMenuComponents;
typedef struct CB4DebugVSelectEntry CB4DebugVSelectEntry;
typedef struct CB4MenuSelectionData CB4MenuSelectionData;

struct CGtState { // 0x10
    uint64_t mID; // GtID
    float mrTimeStateEntered; // RwReal
    void* __vtable; // __vtbl_ptr_type*
};

struct CGtTimer { // 0x2c
    int32_t mnCurrentFrames; // RwInt32
    int32_t mnCurrentFrameCount; // RwInt32
    int32_t mnFramesStopped; // RwInt32
    int32_t mnFramesRunningFullSpeed; // RwInt32
    int32_t mnFramesRunningSlowMo; // RwInt32
    int32_t mnInitFrameCount; // RwInt32
    int32_t mnSlowMoMultiplier; // RwInt32
    float mrTimeStep; // RwReal
    float mrTime; // RwReal
    int32_t mnRequestSlowMoMultiplier; // RwInt32
    bool mbIsRunning;
    uint8_t __pad0[3];
};

struct CGtFSM { // 0x18
    CGtState* mpState;
    void* mpOwner;
    void* mpOffsetTable; // CGtStateOffset*
    CGtTimer* mpStateTimer;
    float mrTimeStateEntered; // RwReal
    void* __vtable; // __vtbl_ptr_type*
};

struct CB4MenuFlowManager { // 0x21E0
    CGtFSM mFSM;
    uint8_t __pad0[0x21C0];
    EB4MenuFlowType meMenuFlowType;
    uint8_t __pad1[4];
};

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

struct CB4DebugVSelectComponent { // 0x14
    CB4DebugMenuComponentBase mBase;
    CB4MenuSelectionData mSelectionData;
    uint8_t** mppcEntriesList; // GtUTF8**
};

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

#endif
