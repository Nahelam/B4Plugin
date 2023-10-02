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

typedef enum {
    eAftertouchTypeNormal = 0,
    eAftertouchTypeCrashbreaker = 1,
    eAftertouchTypeRaceForceAdditive = 2,
    eAftertouchTypeWind = 3,
    eAftertouchTypeCount = 4
} EAftertouchType;

// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4GraphicsManager CB4GraphicsManager;
typedef struct CGtV2d CGtV2d;
typedef struct CB4NetworkManager CB4NetworkManager;

struct CB4GraphicsManager { // 0x12F0
    uint8_t __pad0[0x4A8];
    EB4VideoMode meCurrentVideoMode;
    uint8_t __pad1[0xE44];
};

struct CGtV2d { // 0x8
    float marValues[2];
};

struct CB4NetworkManager { // 0x23980
    uint8_t __pad0[0x23951];
    bool mbIsOnline;
    uint8_t __pad1[0x2E];
};

// --------------------------------
//    Declarations
// --------------------------------

extern bool gCarAirControl;

void CGtFramerateManager__PrepareHook(void* _this); // Good one for executing code that you want to be ran only once per game (also executed once while entering front-end)
void CB4CameraBehaviour__ApplySpeedBasedShakeHook(void* _this, void* lpRaceCarPhysics, float lrShakeScale);

// --------------------------------
//    B4 Variables
// --------------------------------

extern CB4GraphicsManager* gGraphicsManager;
extern void* gAptManager;
extern void* gGame;
extern CB4NetworkManager* gNetworkManager;

// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*CB4GraphicsManager__SetVideoMode_t)(CB4GraphicsManager* _this, EB4VideoMode leVideoMode);
typedef void (*CB4AptManager__SetScreenSettings_t)(void* _this);
typedef void (*CB4Game__SetFrontendFrameRate_t)(void* _this, bool lbSetFrontendFrameRate);
typedef bool (*CB4Game__IsMultiplayerMode_t)(void* _this);
typedef bool (*CB4Game__PrepareWorld_t)(void* _this);
typedef bool (*CB4RaceCarPhysics__ApplyAftertouch_t)(void* _this, EAftertouchType leAftertouchType, bool lbFakeBodyRoll, float lrForceFactor, float lrRollFactor);
typedef void (*CB4CameraBehaviour__ApplySpeedBasedShake_t)(void* _this, void* lpRaceCarPhysics, float lrShakeScale);
typedef void (*CGtFramerateManager__Prepare_t)(void* _this);

extern CB4GraphicsManager__SetVideoMode_t CB4GraphicsManager__SetVideoMode;
extern CB4AptManager__SetScreenSettings_t CB4AptManager__SetScreenSettings;
extern CB4Game__SetFrontendFrameRate_t CB4Game__SetFrontendFrameRate;
extern CB4Game__IsMultiplayerMode_t CB4Game__IsMultiplayerMode;
extern CB4Game__PrepareWorld_t CB4Game__PrepareWorld;
extern CB4RaceCarPhysics__ApplyAftertouch_t CB4RaceCarPhysics__ApplyAftertouch;
extern CB4CameraBehaviour__ApplySpeedBasedShake_t CB4CameraBehaviour__ApplySpeedBasedShake;
extern CGtFramerateManager__Prepare_t CGtFramerateManager__Prepare;

#endif
