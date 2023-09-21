#include "b4p_debug_menu_pages.h"
#include "b4p_debug_test_menu_page.h"

CB4DebugTestMenuPage gDebugTestMenuPage;
CB4DebugTestMenuPage__vtable gDebugTestMenuPage__vtable;

void CB4DebugMenuPages__InitHook()
{
    CB4DebugMenuPages__Init();
    
    gDebugTestMenuPage__vtable.__vtable.Update.__delta = 0;
    gDebugTestMenuPage__vtable.__vtable.Update.__index = 0;
    gDebugTestMenuPage__vtable.__vtable.Update.__pfn = (void*)&CB4DebugTestMenuPage__Update;
    
    gDebugTestMenuPage__vtable.__vtable.Release.__delta = 0;
    gDebugTestMenuPage__vtable.__vtable.Release.__index = 0;
    gDebugTestMenuPage__vtable.__vtable.Release.__pfn = (void*)&CB4DebugTestMenuPage__Release;
    
    gDebugTestMenuPage__vtable.__vtable.ApplyVSelectOption.__delta = 0;
    gDebugTestMenuPage__vtable.__vtable.ApplyVSelectOption.__index = 0;
    gDebugTestMenuPage__vtable.__vtable.ApplyVSelectOption.__pfn = (void*)&CB4DebugTestMenuPage__ApplyVSelectOption;
    
    gDebugTestMenuPage.mBase.__vtable = &gDebugTestMenuPage__vtable;
}
