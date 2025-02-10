#ifndef __SEOKHYUNENGINE_H__
#define __SEOKHYUNENGINE_H__


#include "common.h"
#include "Application.h"
#include "Launcher.h"

#include "Configuration/WindowMode.h"

#include "Platform/AppLauncher.h"
#include "Platform/Window.h"
#include "Platform/RuntimePlatform.h"

#if (OS_INFO == OS_WINDOWS)
#include "Platform/Windows/WindowsWindow.h"
#include "Platform/Windows/WindowsAppLauncher.h"
#elif (OS_INFO == OS_MACOS)
#include "Platform/macOS/macOSWindow.h"
#include "Platform/macOS/macOSAppLauncher.h"
#endif

#include "Utility/Resolution.h"


#endif //__SEOKHYUNENGINE_H__
