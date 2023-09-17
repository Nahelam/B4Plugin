#ifndef B4_DEBUG_MENU_OPTIONS_H_INCLUDED
#define B4_DEBUG_MENU_OPTIONS_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

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

typedef struct CB4GraphicsManager CB4GraphicsManager;

struct CB4GraphicsManager { // 0x12F0
    uint8_t __pad0[0x4A8];
    EB4VideoMode meCurrentVideoMode;
    uint8_t __pad1[0xE44];
};

void ApplyVideoMode(EB4VideoMode leSelectedVideoMode);
void ApplySpeedoUnit(ESpeedoUnit leSelectedSpeedoUnit);

extern CB4GraphicsManager* gGraphicsManager;
extern void* gAptManager;
extern void* gGame;

extern void (*CB4GraphicsManager__SetVideoMode)(CB4GraphicsManager* _this, EB4VideoMode leVideoMode);
extern void (*CB4AptManager__SetScreenSettings)(void* _this);
extern void (*CB4Game__SetFrontendFrameRate)(void* _this, bool lbSetFrontendFrameRate);

#endif
