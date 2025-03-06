#ifndef __WINDOWSWINDOW_H__
#define __WINDOWSWINDOW_H__

#include "common.h"

#include "Platform/Window.h"

class WindowsWindow : public Window
{

private:

    WindowsWindow();

    bool Initialize() override;


public:

    ~WindowsWindow() override;

    // ───────────── STATIC METHODS ─────────────
    static WindowsWindow* Create();
    static WindowsWindow* Create(                             const std::string &title);
    static WindowsWindow* Create(const glm::vec2 &resolution, const std::string &title);
    static WindowsWindow* Create(                             const std::string &title, WindowMode windowMode);
    static WindowsWindow* Create(const glm::vec2 &resolution, const std::string &title, WindowMode windowMode);


    // ───────────── BASIC FUNCTIONS ────────────
    bool Update() override;
    bool Close()  override;

    void setWindowed()   override;
    void setBorderless() override;
    void setFullScreen() override;


    // ───────────── GETTER & SETTER ────────────

    /**
     * @brief A function that automatically sets which monitor a window is positioned on.
     * @warning This has not been tested on multiple monitors.
     */
    void setMonitor()                   override;
    void setMonitor(unsigned int index) override;

    HWND  getWin32Window() { return glfwGetWin32Window(m_handle); }
    HGLRC getWGLContext()  { return glfwGetWGLContext(m_handle);  }
};


#endif //__WINDOWSWINDOW_H__
