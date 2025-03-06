#include "Window.h"
#include "RuntimePlatform.h"


// ─────────────────────────────────────────────────────────────────────────────
//                              CONSTRUCTOR & DESTRUCTOR
// ─────────────────────────────────────────────────────────────────────────────

Window::Window()
{
    WindowHandler::setWindowInstance(this);

    if (!glfwInit())
    {
        const char* description = nullptr;
        glfwGetError(&description);
        std::cerr << "[ERROR] Failed to initialize GLFW: " << description << std::endl;
        exit(-1);
    }

    glfwSetErrorCallback(WindowHandler::GLFWError);
}


Window::~Window()
{
    if (m_handle)
    {
        glfwDestroyWindow(m_handle);
        glfwTerminate();

        WindowHandler::setWindowInstance(nullptr);
        std::cout << "[INFO] GLFW terminated" << std::endl;
    }
}


// ───────────────────────────────────────────────────────────────────────────
//                         GLFW & Window Callbacks
// ───────────────────────────────────────────────────────────────────────────

void Window::OnGLFWError(int error, const char* description)
{

}

void Window::OnMouse(GLFWwindow *window, int button, int action, int mods)
{

}

void Window::OnMouseMove(GLFWwindow *window, double xoffset, double yoffset)
{

}

void Window::OnScroll(GLFWwindow *window, double xoffset, double yoffset)
{

}

void Window::OnKey(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
    {
        glfwSetWindowShouldClose(window, true);
    }

    if ((key == GLFW_KEY_F11 || key == GLFW_KEY_F) && action == GLFW_PRESS)
    {
        switch (m_windowMode)
        {
            case WindowMode::Windowed:
                setBorderless();
                break;

            case WindowMode::Borderless:
                setFullScreen();
                break;

            case WindowMode::Fullscreen:
                setWindowed();
                break;

            default:
                std::cout << "[ERROR] Wrong WindowMode!" << std::endl;
                return;
        }
    }
}

void Window::OnChar(GLFWwindow *window, unsigned int codepoint)
{

}

void Window::OnWindowPos(GLFWwindow *window, int x, int y)
{
    if (m_windowMode == WindowMode::Windowed) m_position.x = x; m_position.y = y;
}

void Window::OnWindowSize(GLFWwindow *window, int width, int height)
{
    m_resolution.x = width; m_resolution.y = height;
}

void Window::OnWindowFramebufferSize(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Window::OnWindowScale(GLFWwindow *window, float xscale, float yscale)
{
    m_scale.x = xscale; m_scale.y = yscale;
}

void Window::OnWindowFocus(GLFWwindow *window, int focused)
{
    m_focused = focused;
}

void Window::OnWindowRefresh(GLFWwindow *window)
{
    this->Update();
    glfwSwapBuffers(window);
}


void Window::OnWindowClose(GLFWwindow *window)
{
    std::cout << "[INFO] Closing Window..." << std::endl;
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}


// ─────────────────────────────────────────────────────────────────────────────
//                                WINDOW FUNCTIONS
// ─────────────────────────────────────────────────────────────────────────────

void Window::setWindowed()
{
    if (m_windowMode == WindowMode::Windowed)
        return;
}

void Window::setBorderless()
{
    if (m_windowMode == WindowMode::Borderless)
        return;
}

void Window::setFullScreen()
{
    if (m_windowMode == WindowMode::Fullscreen)
        return;
}


// ─────────────────────────────────────────────────────────────────────────────
//                                GETTER & SETTER
// ─────────────────────────────────────────────────────────────────────────────

bool Window::Initialize()
{
    return false;
}

bool Window::Update()
{
    return false;
}

bool Window::Close()
{
    delete this;
    return true;
}

void Window::swapBuffers()
{
    glfwSwapBuffers(m_handle);
}

bool Window::windowShouldClose()
{
    return glfwWindowShouldClose(m_handle);
}

void Window::setResolution(glm::vec2 resolution)
{
    m_resolution = resolution;
    glfwSetWindowSize(m_handle, m_resolution.x, m_resolution.y);
}

void Window::setPosition(glm::vec2 position)
{
    m_position = position;
    glfwSetWindowPos(m_handle, m_position.x, m_position.y);
}

void Window::setTitle(std::string title)
{
    m_title = title;
    glfwSetWindowTitle(m_handle, m_title.c_str());
}

void Window::setOpacity(float opacity)
{
    m_opacity = std::clamp(opacity, 0.0f, 1.0f);
    glfwSetWindowOpacity(m_handle, m_opacity);
}

void Window::setvSync(bool vsync)
{
    m_vSync = vsync;
    glfwSwapInterval(m_vSync);
}

void Window::setResizable(bool resizable)
{
    m_resizable = resizable;
    glfwSetWindowAttrib(m_handle, GLFW_RESIZABLE, m_resizable);
}

void Window::setAspectRatioFixed(bool ratiofix)
{
    m_ratiofix = ratiofix;

    if (m_ratiofix) glfwSetWindowAspectRatio(m_handle, m_resolution.x, m_resolution.y);
    else            glfwSetWindowAspectRatio(m_handle, GLFW_DONT_CARE, GLFW_DONT_CARE);
}

void Window::setSizeLimits(bool limitsize)
{
    m_sizeLimits = limitsize;

    if (m_sizeLimits) glfwSetWindowSizeLimits(m_handle, m_minSize.x, m_minSize.y, m_maxSize.x, m_maxSize.y);
    else              glfwSetWindowSizeLimits(m_handle, GLFW_DONT_CARE, GLFW_DONT_CARE, GLFW_DONT_CARE, GLFW_DONT_CARE);
}

//void Window::getMonitorForCoord(glm::ivec2 &coord)
//{
//    int count;
//    GLFWmonitor** monitors = glfwGetMonitors(&count);
//
//    for (int i = 0; i < count; i++)
//    {
//        int x, y;
//        glfwGetMonitorPos(monitors[i], &x, &y);
//
//        const GLFWvidmode* mode = glfwGetVideoMode(monitors[i]);
//
//        if (coord.x >= x && coord.x < x + mode->width &&
//            coord.y >= y && coord.y < y + mode->height)
//        {
//            m_monitor = monitors[i];
//
//            std::cout << "[INFO] Monitor Index: " << i << std::endl;
//            return;
//        }
//    }
//}
//
//void Window::getMonitorForRect(AABB2i rect)
//{
//    int count;
//    GLFWmonitor** monitors = glfwGetMonitors(&count);
//
//    if (count == 1) return;
//
//    if (!monitors)
//    {
//        std::cerr << "[ERROR] Failed to get monitors" << std::endl;
//        return;
//    }
//
//    for (int i = 0; i < count; i++)
//    {
//        if (m_monitor == monitors[i])
//        {
//            std::cout << "[INFO] 현재 모니터에 있음!" << std::endl;
//        }
//
//        int x, y;
//        glfwGetMonitorPos(monitors[i], &x, &y);
//
//        const GLFWvidmode* mode = glfwGetVideoMode(monitors[i]);
//        AABB2i monitorRect = AABB2i(glm::ivec2(x, y), glm::ivec2(x + mode->width, y + mode->height));
//
//        bool isIntersects = monitorRect.intersects(rect);
//
//        if (monitorRect.contains(rect) && isIntersects)
//        {
//            m_monitor = monitors[i];
//            std::cout << "[INFO] Monitor Index: " << i << std::endl;
//
//            return;
//        }
//    }
//}
//
//
//void Window::setWindowMinimize(bool minimaize)
//{
//    NSWindow* nsWindow = getCocoaWindow();
//    if (!nsWindow) return;
//
//    NSUInteger style = [nsWindow styleMask];
//    style &= ~NSWindowStyleMaskMiniaturizable;
//
//    [nsWindow setStyleMask:style];
//}