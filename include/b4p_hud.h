#ifndef B4P_HUD_H_INCLUDED
#define B4P_HUD_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "b4p_vtable.h"
#include "b4p_other.h"

#define MPH_CONV_FACTOR 2.23694f
#define KPH_CONV_FACTOR 3.6f

// --------------------------------
//    Enums
// --------------------------------

typedef enum {
    eHUDTypeNone = 0,
    eHUDTypeRace = 1,
    eHUDTypeRace2P = 2,
    eHUDTypeBurningLap = 3,
    eHUDTypeTimeAttack = 4,
    eHUDTypeLapEliminator = 5,
    eHUDTypeRoadRage = 6,
    eHUDTypeRoadRage2P = 7,
    eHUDTypeTrafficAttack = 8,
    eHUDTypeCrash = 9,
    eHUDTypeCount = 10
} EHUDType;

typedef enum {
    eHUDAlignTop = 0,
    eHUDAlignTopLeft = 1,
    eHUDAlignLeft = 2,
    eHUDAlignBottomLeft = 3,
    eHUDAlignBottom = 4,
    eHUDAlignBottomRight = 5,
    eHUDAlignRight = 6,
    eHUDAlignTopRight = 7,
    eHUDAlignNone = 8,
    eHUDAlignCount = 9
} EHUDAlign;

typedef enum {
    eB4HUDStringRACE = 80,
} EB4HUDString;

typedef enum {
    eFormat_Default = 0,
    eFormat_AlwaysSigned = 1
} ENumericFormat;

typedef enum {
	eStyleTitle = 0,
	eStyleSmallMessage = 1,
	eStyleSmallText = 2,
	eStyleGreyText = 3,
	eStyleBigNumber = 4,
	eStyleMediumNumber = 5,
	eStyleBigMessage = 6,
	eStylePanelMessagePM1 = 7,
	eStylePanelMessageNM1 = 8,
	eStylePanelMessagePM2 = 9,
	eStylePanelMessageNM2 = 10,
	eStyleBoostMultiplier = 11,
	eStyleDigitalNumbers = 12,
	eStyleDigitalTimer = 13,
	eStyleWarningText = 14,
	eStyleRatingText = 15,
	eStyleNum = 16
} EStyle;

// --------------------------------
//    Structs
// --------------------------------

typedef struct CB4HUD CB4HUD;
typedef struct CB4HUDManager CB4HUDManager;
typedef struct CB4HUDComponent CB4HUDComponent;
typedef struct CB4HUDComponent__vtable CB4HUDComponent__vtable;
typedef struct CB4HUDSpeedo CB4HUDSpeedo;
typedef struct CB4HUDPos CB4HUDPos;
typedef struct CB4HUDLap CB4HUDLap;

struct CB4HUD { // 0x2E8
    uint8_t __pad0[0x2E8];
/*
    CB4HUDMessageManager mMessageManager;
    RwReal mrTimer;
    EHUDMode meMode;
    EHUDMode mePrevMode;
    EHUDMode meNextMode;
    bool mbShouldSetMessagesOnHold;
    EPlayerCarIndex mePlayer;
    CGt2dScene mScene;
    CGtV2d mMinPos;
    CGtV2d mMaxPos;
    RwInt32 mnLayerCount;
    RwInt32 mnObjectCount;
    RwInt32 mnChildFrameCount;
    CGt2dFrame *mpClipFrame;
    CB4HUDComponent *mpFirstComponent;
*/
};

struct CB4HUDManager { // 0x5E0
    CB4HUD maHUD[2];
    bool mbHasWideScreenBorders;
    uint8_t __pad0[3];
    int32_t mnNumPlayers; // RwInt32
    EHUDType meHUDType;
    int32_t mePrepareState; // EGtPrepareState
};

struct CB4HUDComponent__vtable { // 0x18
    __vtbl_ptr_type Update;
    __vtbl_ptr_type UpdateTransition;
    __vtbl_ptr_type StartTransition;
};

struct CB4HUDComponent { // 0x20
    CB4HUDManager* mpHUDManager;
    void* mpFrame; // CGt2dFrame
    CB4HUDComponent* mpNext;
    int16_t mnBaseLayer; // RwInt16
    int16_t mnLayerCount; // RwInt16
    int32_t mxFlags; // RwInt32
    EHUDAlign meAlign;
    int8_t mn8Player; // RwInt8
    uint8_t __pad0[3];
    CB4HUDComponent__vtable* __vtable;
};

struct CB4HUDSpeedo { // 0x40
    CB4HUDComponent mComponent;
    void* mapObjects[3]; // CGt2dObject*
    void* mpPlayerCarPhysics; // CB4PlayerCarPhysics
    uint16_t maSpeedString[6];
    float mrSpeed; // RwReal
};

struct CB4HUDPos { // 0x60
    CB4HUDComponent mComponent;
    void* mapObjects[4]; // CGt2dObject
    void* mpRaceCar; // CB4RaceCar
    int32_t mnLastPos; // RwInt32
    int32_t mnLastNumActiveRacesCars; // RwInt32
    float mrTimeLeft; // RwReal
    float mrWarnTimeLeft; // RwReal
    uint16_t maSlashString[4];
    uint16_t maPosString[3];
    uint8_t __pad0[2];
    float mrAnimTime; // RwReal
    float mrPrevFlashUpdateTime; // RwReal
    bool mbWarnLastPlace;
    bool mbCompact;
    bool mbIsCurrentlyShowing;
    bool mbIsCurrentlyInFlashMode;
};

struct CB4HUDLap { // 0x58
    void* mapObjects[4]; // CGt2dObject
    void* mpRaceCar; // CB4RaceCar
    int32_t mnLastLap; // RwInt32
    int32_t mnLastMaxLap; // RwInt32
    float mrTimeLeft; // RwReal
    float mrLastTimeTaken; // RwReal
    float mrMessageTime; // RwReal
    uint16_t maSlashString[3];
    uint16_t maLapString[2];
    bool mbCompact;
    float mrAnimTime; // RwReal
};

// --------------------------------
//    Declarations
// --------------------------------

// void CB4HUDManager__PrepareNormalComponentsHook(CB4HUDManager* _this, EPlayerCarIndex lePlayer);
void CB4HUDManager__RenderHook(CB4HUDManager* _this);
void CB4HUDSpeedo__PrepareHook(void* _this, CGtV2d* lPos, CGtV2d* lHandle, float lrHeight, EStyle leStyle, uint16_t* lpString);
uint16_t* CB4HUDSpeedo__UpdateHook(uint16_t* lpTargetString, int32_t luValue, int32_t lnPrecision, ENumericFormat leFormat);
bool CB4HUDRating__PrepareHook(void* _this, EPlayerCarIndex lePlayer, EHUDAlign leAlign, int32_t lxFlags);
bool CB4HUDGameMode__PrepareHook(void* _this, EPlayerCarIndex lePlayer, EHUDAlign leAlign, int32_t lxFlags, uint16_t* lpString);

// --------------------------------
//    B4 Variables
// --------------------------------

typedef CB4HUDSpeedo gHUDSpeedoComponent_t[2];
typedef CB4HUDPos gHUDPosComponent_t[2];
typedef CB4HUDLap gHUDLapComponent_t[2];

extern CB4HUDManager* gHUDManager;
extern gHUDSpeedoComponent_t* gHUDSpeedoComponent;
extern gHUDPosComponent_t* gHUDPosComponent;
extern gHUDLapComponent_t* gHUDLapComponent;
extern uint16_t** CB4HUDComponent__mgapHUDStrings;

// --------------------------------
//    B4 Functions
// --------------------------------

typedef void (*CB4HUDManager__PrepareNormalComponents_t)(CB4HUDManager* _this, EPlayerCarIndex lePlayer);
typedef void (*CB4HUDManager__Render_t)(CB4HUDManager* _this);
typedef bool (*CB4HUDSpeedo__Prepare_t)(CB4HUDSpeedo* _this, EPlayerCarIndex lePlayer, EHUDAlign leAlign, int32_t lxFlags);
typedef bool (*CB4HUDPos__Prepare_t)(CB4HUDPos* _this, EPlayerCarIndex lePlayer, EHUDAlign leAlign, int32_t lxFlags, bool lbWarnLastPlace, bool lbCompact);
typedef bool (*CB4HUDLap__Prepare_t)(CB4HUDLap* _this, EPlayerCarIndex lePlayer, EHUDAlign leAlign, int32_t lxFlags, bool lbCompact);
typedef bool (*CB4HUDRating__Prepare_t)(void* _this, EPlayerCarIndex lePlayer, EHUDAlign leAlign, int32_t lxFlags);
typedef bool (*CB4HUDGameMode__Prepare_t)(void* _this, EPlayerCarIndex lePlayer, EHUDAlign leAlign, int32_t lxFlags, uint16_t* lpString);
typedef void (*CB4HUDText2dObject__Prepare_t)(void* _this, CGtV2d* lPos, CGtV2d* lHandle, float lrHeight, EStyle leStyle, uint16_t* lpString);
typedef uint16_t* (*CGtUnicode__PrintInt_t)(uint16_t* lpTargetString, int32_t luValue, int32_t lnPrecision, ENumericFormat leFormat);

extern CB4HUDManager__PrepareNormalComponents_t CB4HUDManager__PrepareNormalComponents;
extern CB4HUDManager__Render_t CB4HUDManager__Render;
extern CB4HUDSpeedo__Prepare_t CB4HUDSpeedo__Prepare;
extern CB4HUDPos__Prepare_t CB4HUDPos__Prepare;
extern CB4HUDLap__Prepare_t CB4HUDLap__Prepare;
extern CB4HUDRating__Prepare_t CB4HUDRating__Prepare;
extern CB4HUDGameMode__Prepare_t CB4HUDGameMode__Prepare;
extern CB4HUDText2dObject__Prepare_t CB4HUDText2dObject__Prepare;
extern CGtUnicode__PrintInt_t CGtUnicode__PrintInt;

#endif
