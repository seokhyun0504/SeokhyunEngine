#ifndef __MACOSAPPLAUNCHER_H__
#define __MACOSAPPLAUNCHER_H__

#include "Platform/AppLauncher.h"
#include "Platform/macOS/macOSWindow.h"

class macOSAppLauncher : public AppLauncher
{

private:

    macOSWindow* createWindow() override;


public:

    macOSAppLauncher();
    ~macOSAppLauncher() override;
};


#endif //__MACOSAPPLAUNCHER_H__
