#include "Launcher.h"

#if   OS_INFO == OS_WINDOWS
#include "Platform/Windows/WindowsAppLauncher.h"
#elif OS_INFO == OS_MACOS
#include "Platform/macOS/macOSAppLauncher.h"
#endif

AppLauncher* Launcher::CreateLauncher()
{
    #if   OS_INFO == OS_WINDOWS
    return new WindowsAppLauncher();
    #elif OS_INFO == OS_MACOS
    return new macOSAppLauncher();
    #else
    return nullptr;
    #endif
}



//
//class WindowsAppLauncher;
//class macOSAppLauncher;
//
//AppLauncher* Launcher::CreateLauncher()
//{
//
//    switch (RuntimeInfo::RuntimeOS)
//    {
//        case RuntimeInfo::Windows: return new WindowsAppLauncher();
//        case RuntimeInfo::macOS: return new macOSAppLauncher();
//    }
//
//    return nullptr;
//}