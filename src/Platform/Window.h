#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "common.h"

#include "RuntimePlatform.h"
#include "Math/AABB.h"
#include "Utility/Resolution.h"


enum WindowMode
{
    Windowed   = 0,
    Borderless = 1,
    Fullscreen = 2
};


/**
 * @class Window
 * @brief GLFW-based windows for SeokhyunEngine
 *
 * @warning
 * This class is currently designed for macOS only. It is planned to support cross-platform functionality in the future.
 */
class Window
{

private:

    // ─────────────── ELEMENTS ───────────────
    GLFWwindow *m_window    { nullptr };
    GLFWmonitor *m_monitor  { nullptr };

    glm::ivec2 m_resolution { Resolution::HD };
    glm::ivec2 m_position   { Resolution::UNLIMITED };

    glm::vec2 m_scale       { 1.0f, 1.0f };

    WindowMode m_windowMode { WindowMode::Windowed };

    std::string m_title     { "SeokyunEngine" };

    float m_opacity         { 1.0f };

    bool m_vSync            { true };
    bool m_resizable        { true };
    bool m_visible          { true };
    bool m_ratiofix         { false };

    bool m_sizeLimits       { false };
    glm::ivec2 m_minSize    { Resolution::VGA };
    glm::ivec2 m_maxSize    { Resolution::UNLIMITED };

    bool m_focused          { true };

    Window();

    // ───────────── PRIVATE METHODS ─────────────

    bool initialize();
    bool initializeFullscreen();


    void getMonitor();
    void getMonitor(unsigned int index);

//    void getMonitorForCoord(glm::ivec2 coord);
//    void getMonitorForRect(AABB2i rect);

//    void setWindowMinimize(bool minimaize);


    // ───────────── GLFW CALLBACKS ─────────────
    static Window *s_instance;

    void onGLFWError                (int error, const char* description);

    void onMouse                    (GLFWwindow *window, int button, int action, int mods);
    void onMouseMove                (GLFWwindow *window, double xoffset, double yoffset);
    void onScroll                   (GLFWwindow *window, double xoffset, double yoffset);
    void onKey                      (GLFWwindow *window, int key, int scancode, int action, int mods);
    void onChar                     (GLFWwindow *window, unsigned int codepoint);

    void onWindowPos                (GLFWwindow *window, int x, int y);
    void onWindowSize               (GLFWwindow *window, int width, int height);
    void onWindowFramebufferSize    (GLFWwindow *window, int width, int height);
    void onWindowScale              (GLFWwindow *window, float xscale, float yscale);
    void onWindowFocus              (GLFWwindow *window, int focused);
    void onWindowClose              (GLFWwindow *window);


public:

    ~Window();

    // ───────────── STATIC METHODS ─────────────
    static Window* Create(                             const std::string &title);
    static Window* Create(const glm::vec2 &resolution, const std::string &title);
    static Window* Create(                             const std::string &title, WindowMode windowMode);
    static Window* Create(const glm::vec2 &resolution, const std::string &title, WindowMode windowMode);


    static void GLFWError                          (int error, const char* description)                              { if(s_instance) s_instance->onGLFWError(error, description); }
    static void GLFWMouseCallback                  (GLFWwindow *window, int button, int action, int mods)            { if(s_instance) s_instance->onMouse(window, button, action, mods); }
    static void GLFWMouseMovementCallback          (GLFWwindow *window, double xoffset, double yoffset)              { if(s_instance) s_instance->onMouseMove(window, xoffset, yoffset); }
    static void GLFWMouseScrollCallback            (GLFWwindow *window, double xoffset, double yoffset)              { if(s_instance) s_instance->onScroll(window, xoffset, yoffset); }
    static void GLFWKeyCallback                    (GLFWwindow *window, int key, int scancode, int action, int mods) { if(s_instance) s_instance->onKey(window, key, scancode, action, mods); }
    static void GLFWCharCallback                   (GLFWwindow *window, unsigned int codepoint)                      { if(s_instance) s_instance->onChar(window, codepoint); }

    static void GLFWWindowPosCallback              (GLFWwindow *window, int x, int y)                                { if(s_instance) s_instance->onWindowPos(window, x, y); }
    static void GLFWWindowSizeCallback             (GLFWwindow *window, int width, int height)                       { if(s_instance) s_instance->onWindowSize(window, width, height); }
    static void GLFWWindowFramebufferSizeCallback  (GLFWwindow *window, int width, int height)                       { if(s_instance) s_instance->onWindowFramebufferSize(window, width, height); }
    static void GLFWWindowScaleCallback            (GLFWwindow *window, float xscale, float yscale)                  { if(s_instance) s_instance->onWindowScale(window, xscale, yscale); }
    static void GLFWWindowFocusCallback            (GLFWwindow *window, int focused)                                 { if(s_instance) s_instance->onWindowFocus(window, focused); }
    static void GLFWWindowCloseCallback            (GLFWwindow *window)                                              { if(s_instance) s_instance->onWindowClose(window); }


    // ───────────── PUBLIC METHODS ─────────────

    bool Update();

    void setResolution(glm::vec2 resolution);
    void setPosition(glm::vec2 position);
    void setOpacity(float opacity);
    void setvSync(bool vsync);
    void setResizable(bool resizable);
    void setAspectRatioFixed(bool ratiofix);
    void setSizeLimits(bool limitsize);

    void setFullScreen();
    void setBorderless();
    void setWindowed();

    id getCocoaWindow() { return glfwGetCocoaWindow(m_window); }
    id getNSGLContext() { return glfwGetNSGLContext(m_window); }

};

#endif //__WINDOW_H__