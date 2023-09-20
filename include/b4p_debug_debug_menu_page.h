#ifndef B4P_DEBUG_DEBUG_MENU_PAGE_H_INCLUDED
#define B4P_DEBUG_DEBUG_MENU_PAGE_H_INCLUDED

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

typedef struct CB4DebugDebugMenuPage CB4DebugDebugMenuPage;

struct CB4DebugDebugMenuPage { // 0x28
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

void CB4DebugDebugMenuPage__PrepareHook(CB4DebugDebugMenuPage* _this);
void CB4DebugDebugMenuPage__UpdateHook(CB4DebugDebugMenuPage* _this);

// --------------------------------
//    B4 Variables
// --------------------------------

extern CB4DebugVSelectEntry gaDebugMenuEntries[];

// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4DebugDebugMenuPage__Prepare_t)(CB4DebugDebugMenuPage* _this);
typedef void (*const CB4DebugDebugMenuPage__Update_t)(CB4DebugDebugMenuPage* _this);

extern CB4DebugDebugMenuPage__Prepare_t CB4DebugDebugMenuPage__Prepare;
extern CB4DebugDebugMenuPage__Update_t CB4DebugDebugMenuPage__Update;

#endif
