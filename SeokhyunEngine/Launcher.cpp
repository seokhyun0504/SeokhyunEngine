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