#include <Cocoa/Cocoa.h>
#include <Foundation/Foundation.h>

#include "Window.h"
#include "RuntimePlatform.h"


// ─────────────────────────────────────────────────────────────────────────────
//                              CONSTRUCTOR & DESTRUCTOR
// ─────────────────────────────────────────────────────────────────────────────

Window* Window::s_instance = nullptr;

Window::Window()
{
    s_instance = this;

    if (!glfwInit())
    {
        const char* description = nullptr;
        glfwGetError(&description);
        std::cerr << "[ERROR] Failed to initialize GLFW: " << description << std::endl;
        exit(-1);
    }

    glfwSetErrorCallback(Window::GLFWError);
}


Window::~Window()
{
    if (m_window)
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();

        std::cout << "[INFO] GLFW terminated" << std::endl;
    }
}


// ─────────────────────────────────────────────────────────────────────────────
//                               PRIVATE METHODS
// ─────────────────────────────────────────────────────────────────────────────

bool Window::initialize()
{

#if (OS_INFO == OS_MACOS)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,    GLFW_TRUE);
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, GLFW_TRUE);
#endif

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    glfwWindowHint(GLFW_RESIZABLE, m_resizable);

    m_window = glfwCreateWindow(m_resolution.x, m_resolution.y, m_title.c_str(), m_monitor, nullptr);

    if (!m_window)
    {
        const char* description = nullptr;
        glfwGetError(&description);

        std::cerr << "[ERROR] GLFWwindow was NOT Created!: " << description << std::endl;
        return false;
    }

    glfwSetWindowSizeLimits(m_window, m_minSize.x, m_minSize.y, m_maxSize.x, m_maxSize.y);

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(m_vSync);


    glfwSetMouseButtonCallback(m_window, Window::GLFWMouseCallback);
    glfwSetCursorPosCallback(m_window, Window::GLFWMouseMovementCallback);
    glfwSetScrollCallback(m_window, Window::GLFWMouseScrollCallback);
    glfwSetKeyCallback(m_window, Window::GLFWKeyCallback);
    glfwSetCharCallback(m_window, Window::GLFWCharCallback);

    glfwSetWindowPosCallback(m_window, Window::GLFWWindowPosCallback);
    glfwSetWindowSizeCallback(m_window, Window::GLFWWindowSizeCallback);
    glfwSetFramebufferSizeCallback(m_window, Window::GLFWWindowFramebufferSizeCallback);
    glfwSetWindowContentScaleCallback(m_window, Window::GLFWWindowScaleCallback);
    glfwSetWindowFocusCallback(m_window, Window::GLFWWindowFocusCallback);
    glfwSetWindowCloseCallback(m_window, Window::GLFWWindowCloseCallback);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "[ERROR] failed to initialize glad\n";
        glfwTerminate();

        return false;
    }

    std::cout << "[INFO] Version: "      << glGetString(GL_VERSION)                  << std::endl;
    std::cout << "[INFO] Vendor: "       << glGetString(GL_VENDOR)                   << std::endl;
    std::cout << "[INFO] GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    getMonitor();
    glfwGetWindowPos(m_window, &m_position.x, &m_position.y);


    std::cout << "Current WindowMode: " << m_windowMode << std::endl;
    return true;
}

bool Window::initializeFullscreen()
{
    m_monitor = glfwGetPrimaryMonitor();

    const GLFWvidmode *mode = glfwGetVideoMode(m_monitor);
    std::cout << "FullScreen Width: " << mode->width << " FullScreen Height: " << mode->height << std::endl;

    m_resolution.x = mode->width; m_resolution.y = mode->height;


#if (OS_INFO == OS_MACOS)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,    GLFW_TRUE);
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, GLFW_TRUE);
#endif

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_window = glfwCreateWindow(1280, 720, m_title.c_str(), m_monitor, nullptr);

    if (!m_window)
    {
        const char* description = nullptr;
        glfwGetError(&description);

        std::cerr << "[ERROR] GLFWwindow was NOT Created!: " << description << std::endl;
        return false;
    }

    glfwSetWindowSizeLimits(m_window, m_minSize.x, m_minSize.y, m_maxSize.x, m_maxSize.y);

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(m_vSync);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "[ERROR] failed to initialize glad\n";
        glfwTerminate();

        return false;
    }

    glfwSetMouseButtonCallback(m_window, Window::GLFWMouseCallback);
    glfwSetCursorPosCallback(m_window, Window::GLFWMouseMovementCallback);
    glfwSetScrollCallback(m_window, Window::GLFWMouseScrollCallback);
    glfwSetKeyCallback(m_window, Window::GLFWKeyCallback);
    glfwSetCharCallback(m_window, Window::GLFWCharCallback);

    glfwSetWindowPosCallback(m_window, Window::GLFWWindowPosCallback);
    glfwSetWindowSizeCallback(m_window, Window::GLFWWindowSizeCallback);
    glfwSetFramebufferSizeCallback(m_window, Window::GLFWWindowFramebufferSizeCallback);
    glfwSetWindowFocusCallback(m_window, Window::GLFWWindowFocusCallback);
    glfwSetWindowContentScaleCallback(m_window, Window::GLFWWindowScaleCallback);


    std::cout << "[INFO] Version: "      << glGetString(GL_VERSION)                  << std::endl;
    std::cout << "[INFO] Vendor: "       << glGetString(GL_VENDOR)                   << std::endl;
    std::cout << "[INFO] GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    return true;
}

void Window::getMonitor()
{
    unsigned int monitorIndex = -1;

    NSWindow* nsWindow = getCocoaWindow();
    if (nsWindow)
    {
        NSScreen* currentScreen = [nsWindow screen];
        NSArray<NSScreen*>* screens = [NSScreen screens];

        monitorIndex = [screens indexOfObjectIdenticalTo: currentScreen];
    }

    getMonitor(monitorIndex);
}

void Window::getMonitor(unsigned int index)
{
    int count;
    GLFWmonitor** monitors = glfwGetMonitors(&count);

    m_monitor = monitors[index];

    if (!m_monitor)
    {
        std::cerr << "[ERROR] Failed to get primary monitor" << std::endl;
        return;
    }
}


// ───────────────────────────────────────────────────────────────────────────
//                         GLFW & Window Callbacks
// ───────────────────────────────────────────────────────────────────────────

void Window::onGLFWError(int error, const char* description)
{

}

void Window::onMouse(GLFWwindow *window, int button, int action, int mods)
{

}

void Window::onMouseMove(GLFWwindow *window, double xoffset, double yoffset)
{

}

void Window::onScroll(GLFWwindow *window, double xoffset, double yoffset)
{

}

void Window::onKey(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
    {
        glfwSetWindowShouldClose(window, true);
    }

    if ((key == GLFW_KEY_F11 || key == GLFW_KEY_F) && action == GLFW_RELEASE)
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

void Window::onChar(GLFWwindow *window, unsigned int codepoint)
{

}

void Window::onWindowPos(GLFWwindow *window, int x, int y)
{
    if (m_windowMode == WindowMode::Windowed) m_position.x = x; m_position.y = y;
}

void Window::onWindowSize(GLFWwindow *window, int width, int height)
{
    m_resolution.x = width; m_resolution.y = height;
}

void Window::onWindowFramebufferSize(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Window::onWindowScale(GLFWwindow *window, float xscale, float yscale)
{
    m_scale.x = xscale; m_scale.y = yscale;
}

void Window::onWindowFocus(GLFWwindow *window, int focused)
{
    m_focused = focused;
}

void Window::onWindowClose(GLFWwindow *window)
{
    std::cout << "[INFO] Closing Window..." << std::endl;
    glfwSetWindowShouldClose(window, GLFW_TRUE);

    delete this;
}


// ───────────────────────────────────────────────────────────────────────────
//                             Static Methods
// ───────────────────────────────────────────────────────────────────────────

Window *Window::Create(const std::string &title)
{
    return Create(Resolution::HD, title, WindowMode::Windowed);
}

Window *Window::Create(const glm::vec2 &resolution, const std::string &title)
{
    return Create(resolution, title, WindowMode::Windowed);
}


Window *Window::Create(const std::string &title, WindowMode windowMode)
{
    return Create(Resolution::HD, title, windowMode);
}

Window *Window::Create(const glm::vec2 &resolution, const std::string &title, WindowMode windowMode)
{
    auto window = new Window();

    window->m_resolution = resolution;
    window->m_title      = title;
    window->m_windowMode = windowMode;

    if (!((windowMode == WindowMode::Fullscreen) ? window->initializeFullscreen() : window->initialize()))
    {
        return nullptr;
    }

    return window;
}


// ─────────────────────────────────────────────────────────────────────────────
//                               PUBLIC METHODS
// ─────────────────────────────────────────────────────────────────────────────

bool Window::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    glClearColor(0.2f, 0.1f, 0.3f, 1.0f);


    glfwSwapBuffers(m_window);
    glfwPollEvents();

    return !glfwWindowShouldClose(m_window);
}


void Window::setResolution(glm::vec2 resolution)
{
    m_resolution = resolution;
    glfwSetWindowSize(m_window, m_resolution.x, m_resolution.y);
}

void Window::setPosition(glm::vec2 position)
{
    m_position = position;
    glfwSetWindowPos(m_window, m_position.x, m_position.y);
}

void Window::setOpacity(float opacity)
{
    m_opacity = std::clamp(opacity, 0.0f, 1.0f);
    glfwSetWindowOpacity(m_window, m_opacity);
}

void Window::setvSync(bool vsync)
{
    m_vSync = vsync;
    glfwSwapInterval(m_vSync);
}

void Window::setResizable(bool resizable)
{
    m_resizable = resizable;
    glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, m_resizable);
}

void Window::setAspectRatioFixed(bool ratiofix)
{
    m_ratiofix = ratiofix;

    if (m_ratiofix) glfwSetWindowAspectRatio(m_window, m_resolution.x, m_resolution.y);
    else            glfwSetWindowAspectRatio(m_window, GLFW_DONT_CARE, GLFW_DONT_CARE);
}

void Window::setSizeLimits(bool limitsize)
{
    m_sizeLimits = limitsize;

    if (m_sizeLimits) glfwSetWindowSizeLimits(m_window, m_minSize.x, m_minSize.y, m_maxSize.x, m_maxSize.y);
    else              glfwSetWindowSizeLimits(m_window, GLFW_DONT_CARE, GLFW_DONT_CARE, GLFW_DONT_CARE, GLFW_DONT_CARE);
}

void Window::setWindowed()
{
    if (m_windowMode == WindowMode::Windowed)
        return;

    float xscale, yscale;
    glfwGetWindowContentScale(m_window, &xscale, &yscale);

    setResizable(m_resizable);
    glfwSetWindowMonitor(m_window, nullptr, m_position.x, m_position.y, m_resolution.x / xscale, m_resolution.y / yscale, 0);

    NSWindow *nsWindow = glfwGetCocoaWindow(m_window);
    if (([nsWindow styleMask] & NSWindowStyleMaskFullScreen) == NSWindowStyleMaskFullScreen)
    {
        [nsWindow toggleFullScreen:nil];
        glfwPollEvents();
    }

    m_windowMode = WindowMode::Windowed;
}

void Window::setBorderless()
{
    if (m_windowMode == WindowMode::Borderless)
        return;

    glm::ivec2 windowPos = m_position;
    glm::ivec2 windowSiz = m_resolution;

    NSWindow *nsWindow = getCocoaWindow();
    if (nsWindow)
    {
        [nsWindow toggleFullScreen:nil];
        glfwPollEvents();
    }

    m_position = windowPos;
    m_resolution = windowSiz;

    m_windowMode = WindowMode::Borderless;
}

void Window::setFullScreen()
{
    if (m_windowMode == WindowMode::Fullscreen)
        return;

    glm::ivec2 windowPos = m_position;
    glm::ivec2 windowSiz = m_resolution;

    getMonitor();
    glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, GLFW_FALSE);

    const GLFWvidmode *mode = glfwGetVideoMode(m_monitor);
    glfwSetWindowMonitor(m_window, m_monitor, 0, 0, mode->width, mode->height, mode->refreshRate);

    m_position = windowPos;
    m_resolution = windowSiz;

    m_windowMode = WindowMode::Fullscreen;
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