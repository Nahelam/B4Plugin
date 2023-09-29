#include "b4p_debug_menu_pages.h"
#include "b4p_debug_hud_menu_page.h"
#include "b4p_debug_main_menu_page.h"
#include "b4p_vtable.h"

CB4DebugMenuPageBase* gapDebugMenuPagesBases[NB_PAGES];

CB4DebugMainMenuPage gDebugMainMenuPage;
CB4DebugMainMenuPage__vtable gDebugMainMenuPage__vtable;

CB4DebugHUDMenuPage gDebugHUDMenuPage;
CB4DebugHUDMenuPage__vtable gDebugHUDMenuPage__vtable;

static void InitPagesBases()
{    
    gapDebugMenuPagesBases[0] = &gDebugMainMenuPage.mBase;
    gapDebugMenuPagesBases[1] = &gDebugHUDMenuPage.mBase;
    gapDebugMenuPagesBases[2] = &gDebugMenuPages->mDebugMenu.mBase;
}

static void InitVTable(CB4DebugMenuPageBase* lpPageBase, CB4DebugMenuPageBase__vtable* lpVTable, void* lpfPrepare, void* lpfUpdate, void* lpfRelease)
{
    lpVTable->Prepare.__delta = 0;
    lpVTable->Prepare.__index = 0;
    lpVTable->Prepare.__pfn = lpfPrepare;
    
    lpVTable->Update.__delta = 0;
    lpVTable->Update.__index = 0;
    lpVTable->Update.__pfn = lpfUpdate;

    lpVTable->Release.__delta = 0;
    lpVTable->Release.__index = 0;
    lpVTable->Release.__pfn = lpfRelease;

    lpPageBase->__vtable = lpVTable;
}

static void InitPagesSelections()
{
    CB4DebugHUDMenuPage__InitSelections(&gDebugHUDMenuPage);
}

void CB4DebugMenuPages__InitHook()
{
    CB4DebugMenuPages__Init();
    
    // Only need to set "Prepare" method for the original debug menu
    gDebugMenuPages->mDebugMenu.mBase.__vtable->Prepare.__pfn = CB4DebugOriginalMenuPage__Prepare;
    
    InitPagesBases();
    InitPagesSelections();
    
    InitVTable(&gDebugMainMenuPage.mBase, &gDebugMainMenuPage__vtable.__vtable, (void*)&CB4DebugMainMenuPage__Prepare, (void*)&CB4DebugMainMenuPage__Update, (void*)&CB4DebugMainMenuPage__Release);
    InitVTable(&gDebugHUDMenuPage.mBase, &gDebugHUDMenuPage__vtable.__vtable, (void*)&CB4DebugHUDMenuPage__Prepare, (void*)&CB4DebugHUDMenuPage__Update, (void*)&CB4DebugHUDMenuPage__Release);
}
