#include "WindowHandler.h"
#include "Window.h"


// ─────────────────────────────────────────────────────────────────────────────
//                                   INSTANCE
// ─────────────────────────────────────────────────────────────────────────────

Window* WindowHandler::s_instance = nullptr;


// ─────────────────────────────────────────────────────────────────────────────
//                            GLFW & Window Callbacks
// ─────────────────────────────────────────────────────────────────────────────

void WindowHandler::setWindowInstance(Window* instance)
{
    s_instance = instance;
}

void WindowHandler::GLFWError(int error, const char* description)
{
    if (s_instance)
        s_instance->onGLFWError(error, description);
}

void WindowHandler::GLFWMouseCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (s_instance)
        s_instance->onMouse(window, button, action, mods);
}

void WindowHandler::GLFWMouseMovementCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (s_instance)
        s_instance->onMouseMove(window, xoffset, yoffset);
}

void WindowHandler::GLFWMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (s_instance)
        s_instance->onScroll(window, xoffset, yoffset);
}

void WindowHandler::GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (s_instance)
        s_instance->onKey(window, key, scancode, action, mods);
}

void WindowHandler::GLFWCharCallback(GLFWwindow* window, unsigned int codepoint)
{
    if (s_instance)
        s_instance->onChar(window, codepoint);
}

void WindowHandler::GLFWWindowPosCallback(GLFWwindow* window, int x, int y)
{
    if (s_instance)
        s_instance->onWindowPos(window, x, y);
}

void WindowHandler::GLFWWindowSizeCallback(GLFWwindow* window, int width, int height)
{
    if (s_instance)
        s_instance->onWindowSize(window, width, height);
}

void WindowHandler::GLFWWindowFramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    if (s_instance)
        s_instance->onWindowFramebufferSize(window, width, height);
}

void WindowHandler::GLFWWindowScaleCallback(GLFWwindow* window, float xscale, float yscale)
{
    if (s_instance)
        s_instance->onWindowScale(window, xscale, yscale);
}

void WindowHandler::GLFWWindowFocusCallback(GLFWwindow* window, int focused)
{
    if (s_instance)
        s_instance->onWindowFocus(window, focused);
}

void WindowHandler::GLFWWindowRefreshCallback(GLFWwindow* window)
{
    if (s_instance)
        s_instance->onWindowRefresh(window);
}

void WindowHandler::GLFWWindowCloseCallback(GLFWwindow* window)
{
    if (s_instance)
        s_instance->onWindowClose(window);
}
