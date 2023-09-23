#ifndef B4P_SOUND_H_INCLUDED
#define B4P_SOUND_H_INCLUDED

// --------------------------------
//    Enums
// --------------------------------

typedef enum {
    eSoundFEVertMove = 0,
    eSoundFESelect = 1,
    eSoundFEBack = 2,
    eSoundFECancel = 3,
    eSoundFEIconPop = 4,
    eSoundFELand = 5,
    eSoundFELocked = 6,
    eSoundFETransition = 7,
    eSoundFEOptionsHoriMove = 55
} eSoundFEGeneral;

// --------------------------------
//    Structs
// --------------------------------


// --------------------------------
//    Declarations
// --------------------------------


// --------------------------------
//    B4 Variables
// --------------------------------

extern void* gHUDSoundManager;

// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*CB4HUDSoundManager__HandleFESound_t)(void* _this, eSoundFEGeneral leSound);

extern CB4HUDSoundManager__HandleFESound_t CB4HUDSoundManager__HandleFESound;

#endif
