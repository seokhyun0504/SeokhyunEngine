#ifndef __SEOKHYUNENGINE_H__
#define __SEOKHYUNENGINE_H__


#include "common.h"
#include "Application.h"
#include "Launcher.h"

#include "Configuration/WindowMode.h"

#include "Event/Event.h"
#include "Event/EventDispatcher.h"
#include "Event/EventManager.h"
#include "Event/Input/KeyBoard/KeyBoardEvent.h"
#include "Event/Input/KeyBoard/KeyDownEvent.h"
#include "Event/Input/KeyBoard/KeyUpEvent.h"
#include "Event/Input/Mouse/MouseButtonEvent.h"
#include "Event/Input/Mouse/MouseDownEvent.h"
#include "Event/Input/Mouse/MouseUpEvent.h"
#include "Event/Input/Mouse/MouseMoveEvent.h"
#include "Event/Input/Mouse/MouseScrollEvent.h"
#include "Event/Window/WindowFocusEvent.h"
#include "Event/Window/WindowMoveEvent.h"
#include "Event/Window/WindowResizeEvent.h"
#include "Event/Window/WindowStateEvent.h"

#include "Math/AABB.h"

#include "Platform/AppLauncher.h"
#include "Platform/Window.h"
#include "Platform/RuntimePlatform.h"

#if   OS_INFO == OS_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#include "Platform/Windows/WindowsAppLauncher.h"
#elif OS_INFO == OS_MACOS
#include "Platform/macOS/macOSWindow.h"
#include "Platform/macOS/macOSAppLauncher.h"
#endif

#include "Renderer/OpenGL/Buffer.h"
#include "Renderer/OpenGL/Mesh.h"
#include "Renderer/OpenGL/Program.h"
#include "Renderer/OpenGL/Shader.h"
#include "Renderer/OpenGL/Texture.h"
#include "Renderer/OpenGL/VertexArray.h"

#include "Utility/Resolution.h"


#endif //__SEOKHYUNENGINE_H__
