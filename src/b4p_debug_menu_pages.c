#include "b4p_debug_menu_pages.h"
#include "b4p_debug_test_menu_page.h"
#include "b4p_debug_main_menu_page.h"
#include "b4p_vtable.h"

CB4DebugMenuPageBase* gapDebugMenuPagesBases[NB_PAGES];

CB4DebugTestMenuPage gDebugTestMenuPage;
CB4DebugTestMenuPage__vtable gDebugTestMenuPage__vtable;

CB4DebugMainMenuPage gDebugMainMenuPage;
CB4DebugMainMenuPage__vtable gDebugMainMenuPage__vtable;

static void InitPagesBases()
{    
    gapDebugMenuPagesBases[0] = &gDebugMainMenuPage.mBase;
    gapDebugMenuPagesBases[1] = &gDebugTestMenuPage.mBase;
    gapDebugMenuPagesBases[2] = &gDebugMenuPages->mDebugMenu.mBase;
}

static void InitVTable(CB4DebugMenuPageBase* lpPageBase, CB4DebugMenuPageBase__vtable* lpVTable, void* lpfnPrepare, void* lpfnUpdate, void* lpfnRelease, void* lpfnApplyVSelectOption)
{
    lpVTable->Prepare.__delta = 0;
    lpVTable->Prepare.__index = 0;
    lpVTable->Prepare.__pfn = lpfnPrepare;
    
    lpVTable->Update.__delta = 0;
    lpVTable->Update.__index = 0;
    lpVTable->Update.__pfn = lpfnUpdate;

    lpVTable->Release.__delta = 0;
    lpVTable->Release.__index = 0;
    lpVTable->Release.__pfn = lpfnRelease;

    lpVTable->ApplyVSelectOption.__delta = 0;
    lpVTable->ApplyVSelectOption.__index = 0;
    lpVTable->ApplyVSelectOption.__pfn = lpfnApplyVSelectOption;

    lpPageBase->__vtable = lpVTable;
}

void CB4DebugMenuPages__InitHook()
{
    CB4DebugMenuPages__Init();
    
    // Only need to set "Prepare" method for the original debug menu
    gDebugMenuPages->mDebugMenu.mBase.__vtable->Prepare.__pfn = CB4DebugOriginalMenuPage__Prepare;
    
    InitPagesBases();
    
    InitVTable(&gDebugTestMenuPage.mBase, &gDebugTestMenuPage__vtable.__vtable, (void*)&CB4DebugTestMenuPage__Prepare, (void*)&CB4DebugTestMenuPage__Update, (void*)&CB4DebugTestMenuPage__Release, (void*)&CB4DebugTestMenuPage__ApplyVSelectOption);
    InitVTable(&gDebugMainMenuPage.mBase, &gDebugMainMenuPage__vtable.__vtable, (void*)&CB4DebugTestMenuPage__Prepare, (void*)&CB4DebugMainMenuPage__Update, (void*)&CB4DebugMainMenuPage__Release, (void*)0);
}
