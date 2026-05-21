#pragma once
#include "iaml.h"

extern IAML* aml;

#define MYMOD(__guid, __name, __ver, __author) \
    IAML* aml = nullptr; \
    extern "C" { \
        __attribute__((visibility("default"))) \
        const char* __GetModInfo() { \
            return #__guid "|" #__ver "|" #__name "|" #__author; \
        } \
        __attribute__((visibility("default"))) \
        void __INeedASpecificGame() {} \
    } \
    struct __AMLInit { \
        __AMLInit() { \
            aml = (IAML*)GetInterface("AMLInterface"); \
        } \
    }; \
    static __AMLInit __amlInit __attribute__((init_priority(101)));

#define ON_MOD_PRELOAD() \
    extern "C" __attribute__((visibility("default"))) void OnModPreLoad()

#define ON_MOD_LOAD() \
    extern "C" __attribute__((visibility("default"))) void OnModLoad()
