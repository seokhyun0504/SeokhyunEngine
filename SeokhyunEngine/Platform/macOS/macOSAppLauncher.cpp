#include "macOSAppLauncher.h"

macOSAppLauncher::macOSAppLauncher()
{

}

macOSAppLauncher::~macOSAppLauncher()
{

}


macOSWindow* macOSAppLauncher::createWindow(std::string &appName)
{
    return macOSWindow::Create(appName);
}