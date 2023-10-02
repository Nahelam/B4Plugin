#include "b4p_debug_menu_page_manager.h"

void CB4DebugMenuPageManager__ImmediateLeadOut2(CB4DebugMenuPageManager* _this, EB4MenuFlowEvents leEvent)
{
    CB4DebugMenuPageBase* lpCurrentPage;
    CB4DebugMenuPageBase__vtable *lpVTable;
    CB4DebugMenuComponentBase* lpComponent;
    
    lpCurrentPage = _this->mpCurrentPage;
    lpVTable = lpCurrentPage->__vtable;
    lpComponent = _this->mpFirstComponent;
    
    ((CB4DebugMenuPageBase__Release_t)lpVTable->Release.__pfn)(lpCurrentPage);
    _this->mpCurrentPage = (CB4DebugMenuPageBase*)0;
    
    while (lpComponent)
    {
        if (lpComponent->mbIsActive)
        {
            CB4DebugMenuComponentBase__Release(lpComponent);
        }
        lpComponent = lpComponent->mpNext;
    }

    CB4MenuFlowManager__ApplyEvent(gMenuFlowManager, leEvent, (void*)lpCurrentPage);
}
