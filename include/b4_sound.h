#ifndef B4_SOUND_H_INCLUDED
#define B4_SOUND_H_INCLUDED

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

extern void* gHUDSoundManager;

extern void (*CB4HUDSoundManager__HandleFESound)(void* _this, eSoundFEGeneral leSound);

#endif
