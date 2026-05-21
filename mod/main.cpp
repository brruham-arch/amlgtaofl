#include <android/log.h>
#include <stdio.h>
#include <dlfcn.h>
#include "mod/amlmod.h"

#define TAG     "NPCFight"
#define LOGFILE "/storage/emulated/0/npcfight_log.txt"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

static void logf(const char* msg) {
    FILE* f = fopen(LOGFILE, "a");
    if (f) { fprintf(f, "%s\n", msg); fclose(f); }
    LOGI("%s", msg);
}

MYMOD(com.brruham.npcfight, NPCFight, 1.0, brruham)

ON_MOD_PRELOAD() {
    remove(LOGFILE);
    logf("[NPCFight] OnModPreLoad");
}

ON_MOD_LOAD() {
    logf("[NPCFight] OnModLoad start");

    void* hAML = dlopen("libAML.so", RTLD_NOW | RTLD_NOLOAD);
    if (!hAML) { logf("[NPCFight] ERROR: libAML.so not found"); return; }

    auto getIface = (void*(*)(const char*))dlsym(hAML, "GetInterface");
    if (!getIface) { logf("[NPCFight] ERROR: GetInterface not found"); return; }

    aml = (IAML*)getIface("AMLInterface");
    if (!aml) { logf("[NPCFight] ERROR: aml null"); return; }

    logf("[NPCFight] aml OK");
    aml->ShowToast(false, "[NPCFight] Mod loaded!");
    logf("[NPCFight] OnModLoad done");
}
