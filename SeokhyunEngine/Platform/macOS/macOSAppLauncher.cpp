#include "macOSAppLauncher.h"

macOSAppLauncher::macOSAppLauncher()
{

}

macOSAppLauncher::~macOSAppLauncher()
{

}


macOSWindow* macOSAppLauncher::createWindow()
{
    return macOSWindow::Create();
}