#ifndef B4_STATES_H_INCLUDED
#define B4_STATES_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

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

void CGtFSM__StateEnterHook(CGtFSM* _this, void* lpOldState, void* lpUserData);
void CB4MainMenuState__ActionHook(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
void CB4DebugDebugMenuState__ActionHook(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
void ChangeState(void* _this, uint64_t lu64DestinationState, void* lpUserData);

extern CB4MenuFlowManager* gMenuFlowManager;
extern uint64_t* kB4MainMenuStateID;
extern uint64_t* kB4DebugMenuStateID;

extern CGtState* (*CGtFSM__GetStateFromID)(CGtFSM* _this, uint64_t lStateID);
extern void (*CGtFSM__StateEnter)(CGtFSM* _this, CGtState* lpOldState, void* lpUserData);
extern void (*CGtFSM__StateLeave)(CGtFSM* _this, CGtState* lpNewState, void* lpUserData);
extern void (*CB4MenuFlowManager__ApplyEvent)(CB4MenuFlowManager* _this, uint32_t lnEventID, void* lpUserData);
extern void (*CB4MainMenuState__Action)(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
extern void (*CB4MainMenuState__InitiateConfirm)(void* _this, uint64_t lDestinationState);
extern void (*CB4DebugDebugMenuState__Action)(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);

#endif
