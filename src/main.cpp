//original's first mod 
#include "../extern/beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "../extern/beatsaber-hook/shared/utils/utils.h"
#include "../extern/beatsaber-hook/include/modloader.hpp"
#include "../extern/beatsaber-hook/shared/utils/typedefs.h"
#include "../extern/beatsaber-hook/shared/utils/il2cpp-utils.hpp"

using namespace il2cpp_utils;

MAKE_HOOK_OFFSETLESS(MissedNoteEffect_Init, void, Il2CppObject* self, float _animationDuration) {
    
    SetFieldValue(self, "_animationDuration", 99999999999999999999999.0f);

    MissedNoteEffect_Init(self, _animationDuration);
}

extern "C" void load() {
    //log(INFO, "Hello from il2cpp_init!");
    //log(INFO, "Installing hooks...");

    INSTALL_HOOK_OFFSETLESS(MissedNoteEffect_Init, FindMethodUnsafe("", "MissedNoteEffect", "Init", 1));

    //log(INFO, "Installed all hooks!");
}

enum class Space {
    World,
    Self
};
DEFINE_IL2CPP_ARG_TYPE(Space, "UnityEngine", "Space");