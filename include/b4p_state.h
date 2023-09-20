#ifndef B4P_STATE_H_INCLUDED
#define B4P_STATE_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

// --------------------------------
//    Enums
// --------------------------------

typedef enum {
    eGtStateActionConstruct = 0,
    eGtStateActionDestruct = 1,
    eGtStateActionLeave = 2,
    eGtStateActionEnter = 3,
    eGtStateActionUpdate = 4,
    eGtStateActionEvent = 5
} EGtStateAction;

// --------------------------------
//    Structs
// --------------------------------

typedef struct CGtState CGtState;
typedef struct CGtTimer CGtTimer;
typedef struct CGtFSM CGtFSM;

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

// --------------------------------
//    Declarations
// --------------------------------

void CGtFSM__StateEnterHook(CGtFSM* _this, void* lpOldState, void* lpUserData);
void ChangeState(uint64_t lu64DestinationState, void* lpUserData);

// --------------------------------
//    B4 Variables
// --------------------------------

extern uint64_t* kB4MainMenuStateID;
extern uint64_t* kB4DebugMenuStateID;

// --------------------------------
//    B4 Functions
// --------------------------------

typedef CGtState* (*const CGtFSM__GetStateFromID_t)(CGtFSM* _this, uint64_t lStateID);
typedef void (*const CGtFSM__StateEnter_t)(CGtFSM* _this, CGtState* lpOldState, void* lpUserData);
typedef void (*const CGtFSM__StateLeave_t)(CGtFSM* _this, CGtState* lpNewState, void* lpUserData);

extern CGtFSM__GetStateFromID_t CGtFSM__GetStateFromID;
extern CGtFSM__StateEnter_t CGtFSM__StateEnter;
extern CGtFSM__StateLeave_t CGtFSM__StateLeave;

#endif
