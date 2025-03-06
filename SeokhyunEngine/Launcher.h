#ifndef __LAUNCHER_H__
#define __LAUNCHER_H__

#include "Platform/RuntimePlatform.h"

class AppLauncher;

class Launcher
{

public:

    static AppLauncher* CreateLauncher();
};

#endif //__LAUNCHER_H__
