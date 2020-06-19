//original's first mod 
#include <dlfcn.h>

#include "../extern/beatsaber-hook/include/modloader.hpp"
#include "../extern/beatsaber-hook/shared/utils/utils.h"
#include "../extern/beatsaber-hook/shared/utils/typedefs.h"
#include "../extern/beatsaber-hook/shared/utils/il2cpp-utils.hpp"

using namespace il2cpp_utils;

MAKE_HOOK_OFFSETLESS(MissedNoteEffect_Update, void, Il2CppObject*self) {
    SetFieldValue(self, "_animationDuration", 99999999999999.0f);

    MissedNoteEffect_Update(self);
}

extern "C" void load() {
    //log(INFO, "Hello from il2cpp_init!");
    //log(INFO, "Installing hooks...");

    INSTALL_HOOK_OFFSETLESS(MissedNoteEffect_Update, FindMethod("", "MissedNoteEffect", "Update"));

    //log(INFO, "Installed all hooks!");
}

enum class Space {
    World,
    Self
};
DEFINE_IL2CPP_ARG_TYPE(Space, "UnityEngine", "Space");