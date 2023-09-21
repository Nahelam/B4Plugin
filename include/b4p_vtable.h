#ifndef B4P_VTABLE_H_INCLUDED
#define B4P_VTABLE_H_INCLUDED

typedef struct __vtbl_ptr_type __vtbl_ptr_type;

struct __vtbl_ptr_type { // 0x8
    short int __delta;
    short int __index;
    void* __pfn;
};

#endif
