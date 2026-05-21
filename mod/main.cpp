#include <android/log.h>
#include <stdio.h>

#define TAG     "NPCFight"
#define LOGFILE "/storage/emulated/0/npcfight_log.txt"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define EXPORT  __attribute__((visibility("default")))

static void logf(const char* msg) {
    FILE* f = fopen(LOGFILE, "a");
    if (f) { fprintf(f, "%s\n", msg); fclose(f); }
    LOGI("%s", msg);
}

extern "C" {

EXPORT const char* __GetModInfo() {
    return "com.brruham.npcfight|1.0|NPCFight|brruham";
}

EXPORT void __INeedASpecificGame() {}

EXPORT void OnModPreLoad() {
    remove(LOGFILE);
    logf("[NPCFight] OnModPreLoad OK");
}

EXPORT void OnModLoad() {
    logf("[NPCFight] OnModLoad OK");
}

}
