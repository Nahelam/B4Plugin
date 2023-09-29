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
    ePlayerCarInvalid = -1,
    ePlayerCar0 = 0,
    ePlayerCar1 = 1,
    ePlayerCarCount = 2
} EPlayerCarIndex;

// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4GraphicsManager CB4GraphicsManager;
typedef struct CGtV2d CGtV2d;

struct CB4GraphicsManager { // 0x12F0
    uint8_t __pad0[0x4A8];
    EB4VideoMode meCurrentVideoMode;
    uint8_t __pad1[0xE44];
};

struct CGtV2d { // 0x8
    float marValues[2];
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

typedef void (*CB4GraphicsManager__SetVideoMode_t)(CB4GraphicsManager* _this, EB4VideoMode leVideoMode);
typedef void (*CB4AptManager__SetScreenSettings_t)(void* _this);
typedef void (*CB4Game__SetFrontendFrameRate_t)(void* _this, bool lbSetFrontendFrameRate);
typedef bool (*CB4Game__IsMultiplayerMode_t)(void* _this);

extern CB4GraphicsManager__SetVideoMode_t CB4GraphicsManager__SetVideoMode;
extern CB4AptManager__SetScreenSettings_t CB4AptManager__SetScreenSettings;
extern CB4Game__SetFrontendFrameRate_t CB4Game__SetFrontendFrameRate;
extern CB4Game__IsMultiplayerMode_t CB4Game__IsMultiplayerMode;

#endif
