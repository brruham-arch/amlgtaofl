#pragma once
#include <stdint.h>
#include "interface.h"

class IAML {
public:
    virtual void ShowToast(bool longer, const char* fmt, ...) = 0;
    virtual void* GetSym(const char* lib, const char* sym) = 0;
    virtual int   Hook(void* addr, void* hook, void** orig) = 0;
};
