#ifndef B4P_DEBUG_MENU_PAGES_H_INCLUDED
#define B4P_DEBUG_MENU_PAGES_H_INCLUDED

#include <stdint.h>
#include "b4p_debug_debug_menu_page.h"

// --------------------------------
//    Enums
// --------------------------------


// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4DebugMenuPages CB4DebugMenuPages;

struct CB4DebugMenuPages { // 0x70
    CB4DebugDebugMenuPage mDebugMenu;
    uint8_t __pad0[0x48];
    /*
    CB4DebugHeadingOnlyPage mHeadingOnly;
    CB4DebugLanguageSelectPage mDebugLanguageSelect;
    CB4DebugCarSelectPage mDebugCarSelect;
    CB4DebugOnlineFriendsMenuPage mOnlineFriendsPage;
    */
};

// --------------------------------
//    Declarations
// --------------------------------


// --------------------------------
//    B4 Variables
// --------------------------------

extern CB4DebugMenuPages* gDebugMenuPages;

// --------------------------------
//    B4 Functions
// --------------------------------


#endif
