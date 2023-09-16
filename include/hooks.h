#ifndef HOOKS_H_INCLUDED
#define HOOKS_H_INCLUDED

void CGtFSM__StateEnterHook(CGtFSM* _this, void* lpOldState, void* lpUserData);
void CB4MainMenuState__ActionHook(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
void CB4DebugDebugMenuState__ActionHook(void* _this, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
void CB4DebugVSelectOptionComponent__UpdateHook(CB4DebugVSelectOptionComponent* _this);
void CB4DebugDebugMenuPage__PrepareHook(void* _this);
bool UpdateSelection(CB4DebugVSelectOptionComponent* lpSelector);
void ChangeState(void* _this, uint64_t lDestinationState, void* lpUserData);
void VideoModeConfirm(CB4DebugVSelectOptionComponent* _this);

#endif