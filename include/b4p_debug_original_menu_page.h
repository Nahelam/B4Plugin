#ifndef B4P_DEBUG_ORIGINAL_MENU_PAGE_H_INCLUDED
#define B4P_DEBUG_ORIGINAL_MENU_PAGE_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "b4p_debug_menu_page_base.h"
#include "b4p_debug_vselect_option_component.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugOriginalMenuPage CB4DebugOriginalMenuPage;

struct CB4DebugOriginalMenuPage { // 0x28
    CB4DebugMenuPageBase mBase;
    int32_t meMenuGameMode; // EB4MenuGameMode
    uint64_t mTrackID; // GtID
    uint64_t mCarID; // GtID
    int32_t mnCarColour; // RwInt32
    int32_t mnNumAICars; // RwInt32
    bool mbIsOnline;
    bool mbTrafficOn;
    bool mbIsNewMenuFlow;
    bool mbIsDebugProgression;
    int32_t mnEventNumber; // RwInt32
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

typedef void (*const CB4DebugOriginalMenuPage__Prepare_t)(CB4DebugOriginalMenuPage* _this);
typedef void (*const CB4DebugOriginalMenuPage__Update_t)(CB4DebugOriginalMenuPage* _this);

extern CB4DebugOriginalMenuPage__Prepare_t CB4DebugOriginalMenuPage__Prepare;
extern CB4DebugOriginalMenuPage__Update_t CB4DebugOriginalMenuPage__Update;

#endif
