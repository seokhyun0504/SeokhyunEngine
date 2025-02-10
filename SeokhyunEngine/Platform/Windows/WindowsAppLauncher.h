#ifndef __WINDOWSAPPLAUNCHER_H__
#define __WINDOWSAPPLAUNCHER_H__

#include "Platform/AppLauncher.h"
#include "Platform/Windows/WindowsWindow.h"

class WindowsAppLauncher : public AppLauncher
{

private:

    WindowsWindow* createWindow() override;


public:

    WindowsAppLauncher();
    ~WindowsAppLauncher();
};


#endif //__WINDOWSAPPLAUNCHER_H__
