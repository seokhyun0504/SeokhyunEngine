#ifndef __MACOSWINDOW_H__
#define __MACOSWINDOW_H__

#include "common.h"

#include "Platform/Window.h"
#include "Platform/WindowHandler.h"


class macOSWindow : public Window
{

private:

    glm::vec2 m_retinaScale { glm::ivec2(1) };

    macOSWindow();

    bool Initialize() override;


public:

    ~macOSWindow() override;


    // ───────────── STATIC METHODS ─────────────
    static macOSWindow* Create();
    static macOSWindow* Create(                             const std::string &title);
    static macOSWindow* Create(const glm::vec2 &resolution, const std::string &title);
    static macOSWindow* Create(                             const std::string &title, WindowMode windowMode);
    static macOSWindow* Create(const glm::vec2 &resolution, const std::string &title, WindowMode windowMode);


    // ───────────── BASIC FUNCTIONS ────────────
    bool Update() override;
    bool Close()  override;

    void setWindowed()   override;

    /**
     * @brief Maximize the macOS window instead of switching to Boderless.
     * @warning There is a bug where input is ignored once when executing the function with a designated key.
     */
    void setBorderless() override;
    void setFullScreen() override;


    // ───────────── GETTER & SETTER ────────────
    void setMonitor()                   override;
    void setMonitor(unsigned int index) override;

    id getCocoaWindow() { return glfwGetCocoaWindow(m_handle); }
    id getNSGLContext() { return glfwGetNSGLContext(m_handle); }
};


#endif //__MACOSWINDOW_H__
