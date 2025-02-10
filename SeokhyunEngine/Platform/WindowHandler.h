#ifndef __WINDOWHANDLER_H__
#define __WINDOWHANDLER_H__

#include "common.h"
#include "Utility/Resolution.h"

class Window;

class WindowHandler
{

private:

    static Window* s_instance;


protected:

    glm::ivec2 m_windowedSize;
    glm::ivec2 m_windowedPos;

    glm::ivec2 m_minSize    { Resolution::VGA };
    glm::ivec2 m_maxSize    { Resolution::UNLIMITED };

    bool m_focused;
//    bool

public:

    // ──────────── GETTER & SETTER ────────────
    glm::ivec2 getminSize() { return m_minSize; }
    glm::ivec2 getmaxSize() { return m_minSize; }

    glm::ivec2 getwindowedSize() { return m_windowedSize; }
    glm::ivec2 getwindowedPos()  { return m_windowedPos; }

    bool isFocused() { return m_focused; }



    static void setWindowInstance(Window* instance);

    // ─────────────── CALLBACKS ───────────────
    static void GLFWError                         (int error, const char* description);
    static void GLFWMouseCallback                 (GLFWwindow *window, int button, int action, int mods);
    static void GLFWMouseMovementCallback         (GLFWwindow *window, double xoffset, double yoffset);
    static void GLFWMouseScrollCallback           (GLFWwindow *window, double xoffset, double yoffset);
    static void GLFWKeyCallback                   (GLFWwindow *window, int key, int scancode, int action, int mods);
    static void GLFWCharCallback                  (GLFWwindow *window, unsigned int codepoint);

    static void GLFWWindowPosCallback             (GLFWwindow *window, int x, int y);
    static void GLFWWindowSizeCallback            (GLFWwindow *window, int width, int height);
    static void GLFWWindowFramebufferSizeCallback (GLFWwindow *window, int width, int height);
    static void GLFWWindowScaleCallback           (GLFWwindow *window, float xscale, float yscale);
    static void GLFWWindowFocusCallback           (GLFWwindow *window, int focused);
    static void GLFWWindowRefreshCallback         (GLFWwindow *window);
    static void GLFWWindowCloseCallback           (GLFWwindow *window);
};


#endif //__WINDOWHANDLER_H__
