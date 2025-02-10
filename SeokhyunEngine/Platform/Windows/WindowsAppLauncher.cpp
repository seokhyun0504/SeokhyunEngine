#include "WindowsAppLauncher.h"

WindowsAppLauncher::WindowsAppLauncher()
{

}

WindowsAppLauncher::~WindowsAppLauncher()
{

}


WindowsWindow* WindowsAppLauncher::createWindow()
{
    return WindowsWindow::Create();
}