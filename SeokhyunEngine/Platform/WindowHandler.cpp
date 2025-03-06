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
        s_instance->OnGLFWError(error, description);
}

void WindowHandler::GLFWMouseCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (s_instance)
        s_instance->OnMouse(window, button, action, mods);
}

void WindowHandler::GLFWMouseMovementCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (s_instance)
        s_instance->OnMouseMove(window, xoffset, yoffset);
}

void WindowHandler::GLFWMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (s_instance)
        s_instance->OnScroll(window, xoffset, yoffset);
}

void WindowHandler::GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (s_instance)
        s_instance->OnKey(window, key, scancode, action, mods);
}

void WindowHandler::GLFWCharCallback(GLFWwindow* window, unsigned int codepoint)
{
    if (s_instance)
        s_instance->OnChar(window, codepoint);
}

void WindowHandler::GLFWWindowPosCallback(GLFWwindow* window, int x, int y)
{
    if (s_instance)
        s_instance->OnWindowPos(window, x, y);
}

void WindowHandler::GLFWWindowSizeCallback(GLFWwindow* window, int width, int height)
{
    if (s_instance)
        s_instance->OnWindowSize(window, width, height);
}

void WindowHandler::GLFWWindowFramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    if (s_instance)
        s_instance->OnWindowFramebufferSize(window, width, height);
}

void WindowHandler::GLFWWindowScaleCallback(GLFWwindow* window, float xscale, float yscale)
{
    if (s_instance)
        s_instance->OnWindowScale(window, xscale, yscale);
}

void WindowHandler::GLFWWindowFocusCallback(GLFWwindow* window, int focused)
{
    if (s_instance)
        s_instance->OnWindowFocus(window, focused);
}

void WindowHandler::GLFWWindowRefreshCallback(GLFWwindow* window)
{
    if (s_instance)
        s_instance->OnWindowRefresh(window);
}

void WindowHandler::GLFWWindowCloseCallback(GLFWwindow* window)
{
    if (s_instance)
        s_instance->OnWindowClose(window);
}
