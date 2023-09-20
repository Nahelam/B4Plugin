#ifndef B4P_OTHER_H_INCLUDED
#define B4P_OTHER_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

// --------------------------------
//    Enums
// --------------------------------

typedef enum {
    eB4VideoModeNTSC = 0,
    eB4VideoModeHDTV = 1,
    eB4VideoModePAL = 2,
    eB4VideoModeMax = 3
} EB4VideoMode;

typedef enum {
    eSpeedoUnitMPH = 0,
    eSpeedoUnitKPH = 1
} ESpeedoUnit;

// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4GraphicsManager CB4GraphicsManager;

struct CB4GraphicsManager { // 0x12F0
    uint8_t __pad0[0x4A8];
    EB4VideoMode meCurrentVideoMode;
    uint8_t __pad1[0xE44];
};

// --------------------------------
//    Declarations
// --------------------------------


// --------------------------------
//    B4 Variables
// --------------------------------

extern CB4GraphicsManager* gGraphicsManager;
extern void* gAptManager;
extern void* gGame;

// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*const CB4GraphicsManager__SetVideoMode_t)(CB4GraphicsManager* _this, EB4VideoMode leVideoMode);
typedef void (*const CB4AptManager__SetScreenSettings_t)(void* _this);
typedef void (*const CB4Game__SetFrontendFrameRate_t)(void* _this, bool lbSetFrontendFrameRate);

extern CB4GraphicsManager__SetVideoMode_t CB4GraphicsManager__SetVideoMode;
extern CB4AptManager__SetScreenSettings_t CB4AptManager__SetScreenSettings;
extern CB4Game__SetFrontendFrameRate_t CB4Game__SetFrontendFrameRate;

#endif
