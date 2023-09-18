#ifndef B4P_FLOW_H_INCLUDED
#define B4P_FLOW_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

// --------------------------------
//    Enums
// --------------------------------

typedef enum {
    eB4MenuFlowNormal = 0,
    eB4MenuFlowCount = 1
} EB4MenuFlowType;

typedef enum {
    eGtStateActionConstruct = 0,
    eGtStateActionDestruct = 1,
    eGtStateActionLeave = 2,
    eGtStateActionEnter = 3,
    eGtStateActionUpdate = 4,
    eGtStateActionEvent = 5
} EGtStateAction;

typedef enum {
    eMenuFlowEventMenuPageForward = 0,
    eMenuFlowEventMenuPageBack = 1,
    eMenuFlowEventMenuPageSelectedOption = 2,
    eMenuFlowEventMenuPageFlashEvent = 3,
    eMenuFlowEventMenuPageInputEvent = 4,
    eMenuFlowEventMenuPageDebugButtonEvent = 5,
    eMenuFlowEventBootedOutOfGame = 6,
    eMenuFlowEventBootedOutOfUserSet = 7,
    eMenuFlowEventPlayerListChanged = 8,
    eMenuFlowEventMessageBox = 9,
    eMenuFlowEventCustomStringsCleared = 10,
    eMenuFlowEventDownloadRecordDetails = 11,
    eMenuFlowEventDownloadRecordComplete = 12,
    eMenuFlowEventMax = 13
} EB4MenuFlowEvents;

// --------------------------------
//    Structs
// --------------------------------

typedef struct CGtState CGtState;
typedef struct CGtTimer CGtTimer;
typedef struct CGtFSM CGtFSM;
typedef struct CB4MenuFlowManager CB4MenuFlowManager;

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

// --------------------------------
//    Declarations
// --------------------------------

void CGtFSM__StateEnterHook(CGtFSM* _this, void* lpOldState, void* lpUserData);
void CB4MainMenuState__ActionHook(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
void CB4DebugDebugMenuState__ActionHook(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
void ChangeState(void* _this, uint64_t lu64DestinationState, void* lpUserData);

// --------------------------------
//    B4 Variables
// --------------------------------

extern CB4MenuFlowManager* gMenuFlowManager;
extern uint64_t* kB4MainMenuStateID;
extern uint64_t* kB4DebugMenuStateID;

// --------------------------------
//    B4 Functions
// --------------------------------

typedef CGtState* (*const CGtFSM__GetStateFromID_t)(CGtFSM* _this, uint64_t lStateID);
typedef void (*const CGtFSM__StateEnter_t)(CGtFSM* _this, CGtState* lpOldState, void* lpUserData);
typedef void (*const CGtFSM__StateLeave_t)(CGtFSM* _this, CGtState* lpNewState, void* lpUserData);
typedef void (*const CB4MenuFlowManager__ApplyEvent_t)(CB4MenuFlowManager* _this, uint32_t lnEventID, void* lpUserData);
typedef void (*const CB4State__Action_t)(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
typedef void (*const CB4MainMenuState__InitiateConfirm_t)(void* _this, uint64_t lDestinationState);
typedef void (*const CB4DebugMenuPageManager__ImmediateLeadOut_t)(void* _this, EB4MenuFlowEvents leEvent);

extern CGtFSM__GetStateFromID_t CGtFSM__GetStateFromID;
extern CGtFSM__StateEnter_t CGtFSM__StateEnter;
extern CGtFSM__StateLeave_t CGtFSM__StateLeave;
extern CB4MenuFlowManager__ApplyEvent_t CB4MenuFlowManager__ApplyEvent;
extern CB4State__Action_t CB4MainMenuState__Action;
extern CB4State__Action_t CB4DebugDebugMenuState__Action;
extern CB4MainMenuState__InitiateConfirm_t CB4MainMenuState__InitiateConfirm;
extern CB4DebugMenuPageManager__ImmediateLeadOut_t CB4DebugMenuPageManager__ImmediateLeadOut;

#endif
