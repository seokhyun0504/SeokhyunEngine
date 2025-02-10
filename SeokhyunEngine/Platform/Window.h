#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "common.h"

#include "Configuration/WindowMode.h"
#include "RuntimePlatform.h"
#include "WindowHandler.h"
#include "Utility/Resolution.h"


/**
 * @class Window
 * @brief GLFW-based cross-platform windows for SeokhyunEngine
 */
class Window : public WindowHandler
{

protected:

    GLFWwindow *m_handle        { nullptr };
    GLFWmonitor *m_monitor      { nullptr };

    glm::ivec2 m_resolution     { Resolution::HD };
    glm::ivec2 m_position       { Resolution::UNLIMITED };
    glm::ivec2 m_scale          { glm::vec2(1.0f) };

    WindowMode m_windowMode     { WindowMode::Windowed };

    std::string m_title         { "SeokyunEngine" };

    float m_opacity             { 1.0f };

    bool m_vSync                { false };
    bool m_resizable            { true };
    bool m_visible              { false };
    bool m_ratiofix             { false };

    bool m_sizeLimits           { false };


    Window();
    virtual ~Window();


    // ───────────── GLFW CALLBACKS ─────────────
    virtual void onGLFWError                (int error, const char* description);

    virtual void onMouse                    (GLFWwindow *window, int button, int action, int mods);
    virtual void onMouseMove                (GLFWwindow *window, double xoffset, double yoffset);
    virtual void onScroll                   (GLFWwindow *window, double xoffset, double yoffset);
    virtual void onKey                      (GLFWwindow *window, int key, int scancode, int action, int mods);
    virtual void onChar                     (GLFWwindow *window, unsigned int codepoint);

    virtual void onWindowPos                (GLFWwindow *window, int x, int y);
    virtual void onWindowSize               (GLFWwindow *window, int width, int height);
    virtual void onWindowFramebufferSize    (GLFWwindow *window, int width, int height);
    virtual void onWindowScale              (GLFWwindow *window, float xscale, float yscale);
    virtual void onWindowFocus              (GLFWwindow *window, int focused);
    virtual void onWindowRefresh            (GLFWwindow *window);
    virtual void onWindowClose              (GLFWwindow *window);


    // ──────────── WINDOW FUNCTIONS ───────────
    virtual bool Initialize();

public:

    virtual bool Update();
    virtual bool Close();

    virtual void pollEvents();
    virtual bool windowShouldClose();

    virtual void setWindowed();
    virtual void setBorderless();
    virtual void setFullScreen();


    // ───────────── GETTER & SETTER ────────────
    virtual glm::ivec2 getResolution()  { return m_resolution; }
    virtual glm::ivec2 getPosition()    { return m_position;   }

    virtual std::string getTitle() { return m_title; }


    virtual void setMonitor()                   = 0;
    virtual void setMonitor(unsigned int index) = 0;

    void setResolution(glm::vec2 resolution);
    void setPosition(glm::vec2 position);
    void setTitle(std::string title);
    void setOpacity(float opacity);
    void setvSync(bool vsync);
    void setResizable(bool resizable);
    void setAspectRatioFixed(bool ratiofix);
    void setSizeLimits(bool limitsize);


    friend class WindowHandler;
};

#endif //__WINDOW_H__