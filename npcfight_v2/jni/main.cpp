#include <jni.h>
#include <android/log.h>

#define TAG "NPCFight"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

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
    "NPC Fight",
    "brruham",
    "com.rockstargames.gtasa"
};

extern "C" {

ModInfo* __GetModInfo() { return &modInfo; }
void __INeedASpecificGame() {}

void OnModLoad() {
    LOGI("NPCFight: OnModLoad called!");
}

}
