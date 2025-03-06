#include "WindowsAppLauncher.h"

WindowsAppLauncher::WindowsAppLauncher()
{

}

WindowsAppLauncher::~WindowsAppLauncher()
{

}


WindowsWindow* WindowsAppLauncher::createWindow(std::string &appName)
{
    return WindowsWindow::Create(appName);
}