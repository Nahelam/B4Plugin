#ifndef SYMBOLS_H_INCLUDED
#define SYMBOLS_H_INCLUDED

#include <stdbool.h>
#include "structs.h"
#include "enums.h"

void* gInputManager = 0x4F33C0;
CB4MenuFlowManager* gMenuFlowManager = 0x1C11160;
void* gHUDSoundManager = 0x1C891B0;
void* gDebugMenu = 0x1C10EF0;
CB4DebugMenuComponents* gDebugMenuComponents = 0x1C10EA0;
void* gDebugMenuPageManager = 0x1C10EE0;
CB4GraphicsManager* gGraphicsManager = 0x1BFE760;
void* gAptManager = 0x1C0A2D0;
void* gGame = 0x4F3300;
uint64_t* kB4MainMenuStateID = 0x4B80F8;
uint64_t* kB4DebugMenuStateID = 0x4B6860;

void (*CB4GraphicsManager__SetVideoMode)(CB4GraphicsManager* _this, EB4VideoMode leVideoMode) = 0x14C338;
void (*CB4AptManager__SetScreenSettings)(void* _this) = 0x17D370;
void (*CB4Game__SetFrontendFrameRate)(void* _this, bool lbSetFrontendFrameRate) = 0x1125C0;

CGtState* (*CGtFSM__GetStateFromID)(CGtFSM* _this, uint64_t lStateID) = 0x2FED60;
void (*CGtFSM__StateEnter)(CGtFSM* _this, CGtState* lpOldState, void* lpUserData) = 0x2FEDE0;
void (*CGtFSM__StateLeave)(CGtFSM* _this, CGtState* lpNewState, void* lpUserData) = 0x2FEDA0;

void (*CB4MenuFlowManager__ApplyEvent)(CB4MenuFlowManager* _this, uint32_t lnEventID, void* lpUserData) = 0x187AF0;

float (*CB4ControllerMapping__GetPadControl)(void* _this, EGtPS2DualShockDeviceControl lePadControl, bool lbDebounced, uint8_t ln8Player) = 0x113000;
bool (*CB4InputManager__GetMenuButton)(void* _this, EMenuControls leMenuButton, int8_t ln8Player) = 0x105C48;

void (*CB4MainMenuState__Action)(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData) = 0x1943A8;
void (*CB4MainMenuState__InitiateConfirm)(void* _this, uint64_t lDestinationState) = 0x194540;

void (*CB4DebugDebugMenuState__Action)(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData) = 0x192248;
void (*CB4DebugMenuPageBase__Prepare)(void* _this) = 0x186DF0;
void (*CB4DebugDebugMenuPage__Prepare)(void* _this) = 0x186768;
void (*CB4DebugDebugMenuPage__Update)(void* _this) = 0x1869F0;
void (*CB4DebugBackgroundComponent__Prepare)(CB4DebugBackgroundComponent* _this) = 0x187078;
void (*CB4DebugVSelectEntry__Prepare)(CB4DebugVSelectEntry* _this, char* lpcEntryName, char** lppcOptionsList, int lnNumOptions, int lnInitialOptionSelection) = 0x1877A8;
void (*CB4DebugVSelectOptionComponent__Prepare)(CB4DebugVSelectOptionComponent* _this, CB4DebugVSelectEntry* lpEntries, int lnNumEntries) = 0x1877E0;
void (*CB4DebugMenuPageManager__ImmediateLeadOut)(void* _this, EB4MenuFlowEvents leEvent) = 0x185DC8;

bool (*CB4MenuSelectionData__SelectNext)(CB4MenuSelectionData* _this) = 0x183F18;
bool (*CB4MenuSelectionData__SelectPrev)(CB4MenuSelectionData* _this) = 0x183EF8;

void (*CB4HUDSoundManager__HandleFESound)(void* _this, eSoundFEGeneral leSound) = 0x235DC8;

void (*CGt2dFont__RenderStringJustified)(void* _this, short* lpString, float lrPosX, float lrPosY, float lrHeight, CGtV4d lColour, float lrHandle) = 0x31F940;

#endif
