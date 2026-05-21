#include <android/log.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

#define TAG     "NPCFight"
#define LOGFILE "/storage/emulated/0/npcfight_log.txt"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define EXPORT  __attribute__((visibility("default")))

static void logf(const char* msg) {
    FILE* f = fopen(LOGFILE, "a");
    if (f) { fprintf(f, "%s\n", msg); fclose(f); }
    LOGI("%s", msg);
}

// ModInfo dengan constructor seperti libFullscreenSplash
class ModInfo {
public:
    char szGUID[64];
    char szVersion[16];
    char szName[64];
    char szAuthor[32];

    ModInfo(const char* name, const char* author, 
            const char* guid, const char* version) {
        strncpy(szName,    name,    sizeof(szName)-1);
        strncpy(szAuthor,  author,  sizeof(szAuthor)-1);
        strncpy(szGUID,    guid,    sizeof(szGUID)-1);
        strncpy(szVersion, version, sizeof(szVersion)-1);
    }
};

static ModInfo modinfo(
    "NPCFight",
    "brruham",
    "com.brruham.npcfight",
    "1.0"
);

extern "C" {

EXPORT ModInfo* __GetModInfo() { return &modinfo; }
EXPORT void __INeedASpecificGame() {}

EXPORT void OnModLoad() {
    remove(LOGFILE);
    logf("[NPCFight] OnModLoad OK");

    void* hAML = dlopen("libAML.so", RTLD_NOW | RTLD_NOLOAD);
    logf(hAML ? "[NPCFight] libAML found" : "[NPCFight] libAML NOT found");

    auto getIface = hAML ? (void*(*)(const char*))dlsym(hAML, "GetInterface") : nullptr;
    logf(getIface ? "[NPCFight] GetInterface found" : "[NPCFight] GetInterface NOT found");
}

}
