#include <android/log.h>
#include <stdio.h>
#include <stdint.h>

#define TAG     "NPCFight"
#define LOGFILE "/storage/emulated/0/npcfight_log.txt"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define EXPORT  __attribute__((visibility("default")))

static void logf(const char* msg) {
    FILE* f = fopen(LOGFILE, "a");
    if (f) { fprintf(f, "%s\n", msg); fclose(f); }
    LOGI("%s", msg);
}

struct ModInfo {
    const char* szGUID;
    const char* szVersion;
    const char* szName;
    const char* szAuthor;
    const char* szGameGUID;
};

static ModInfo modInfo = {
    "com.brruham.npcfight",
    "1.0",
    "NPCFight",
    "brruham",
    "com.rockstargames.gtasa"
};

extern "C" {

EXPORT ModInfo* __GetModInfo() { return &modInfo; }
EXPORT void __INeedASpecificGame() {}

EXPORT void OnModLoad() {
    remove(LOGFILE);
    logf("[NPCFight] OnModLoad OK");
}

}
