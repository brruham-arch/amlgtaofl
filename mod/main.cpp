#include <android/log.h>
#include "mod/amlmod.h"

#define TAG "NPCFight"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGFILE "/storage/emulated/0/npcfight_log.txt"

static void logf(const char* msg) {
    FILE* f = fopen(LOGFILE, "a");
    if (f) { fprintf(f, "%s\n", msg); fclose(f); }
    LOGI("%s", msg);
}

MYMOD(com.brruham.npcfight, NPCFight, 1.0, brruham)

ON_MOD_PRELOAD() {
    remove(LOGFILE);
    logf("[NPCFight] OnModPreLoad called");
}

ON_MOD_LOAD() {
    logf("[NPCFight] OnModLoad called");
    aml->ShowToast(false, "[NPCFight] Mod loaded!");
    logf("[NPCFight] OnModLoad DONE");
}
