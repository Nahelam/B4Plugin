#ifndef B4P_MENU_FLOW_MANAGER_H_INCLUDED
#define B4P_MENU_FLOW_MANAGER_H_INCLUDED

#include "b4p_state.h"

// --------------------------------
//    Enums
// --------------------------------

typedef enum {
    eB4MenuFlowNormal = 0,
    eB4MenuFlowCount = 1
} EB4MenuFlowType;

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

typedef struct CB4MenuFlowManager CB4MenuFlowManager;

// 0xB10 debugdebug state
// 0xD78 main menu state

struct CB4MenuFlowManager { // 0x21E0
    CGtFSM mFSM;
    uint8_t __pad0[0x21C0];
    EB4MenuFlowType meMenuFlowType;
    uint8_t __pad1[4];
};

// --------------------------------
//    Declarations
// --------------------------------


// --------------------------------
//    B4 Variables
// --------------------------------

extern CB4MenuFlowManager* gMenuFlowManager;

// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4MenuFlowManager__ApplyEvent_t)(CB4MenuFlowManager* _this, uint32_t lnEventID, void* lpUserData);

extern CB4MenuFlowManager__ApplyEvent_t CB4MenuFlowManager__ApplyEvent;

#endif
