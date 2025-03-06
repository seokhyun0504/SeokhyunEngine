#include <Cocoa/Cocoa.h>
#include <Foundation/Foundation.h>

#include "macOSWindow.h"

// ─────────────────────────────────────────────────────────────────────────────
//                              CONSTRUCTOR & DESTRUCTOR
// ─────────────────────────────────────────────────────────────────────────────

macOSWindow::macOSWindow()
{

}


macOSWindow::~macOSWindow()
{

}


// ─────────────────────────────────────────────────────────────────────────────
//                               PRIVATE METHODS
// ─────────────────────────────────────────────────────────────────────────────

bool macOSWindow::Initialize()
{
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,    GLFW_TRUE);
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, GLFW_TRUE);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    glfwWindowHint(GLFW_RESIZABLE, m_resizable);

    m_handle = glfwCreateWindow(m_resolution.x, m_resolution.y, m_title.c_str(), nullptr, nullptr);

    if (!m_handle)
    {
        const char* description = nullptr;
        glfwGetError(&description);

        std::cerr << "[ERROR] GLFWwindow was NOT Created!: " << description << std::endl;
        return false;
    }

    if (!m_resizable)
    {
        glfwSetWindowSizeLimits(m_handle, getminSize().x, getminSize().y, getmaxSize().x, getmaxSize().y);
    }


    glfwMakeContextCurrent(m_handle);
    glfwSwapInterval(m_vSync);


    glfwSetMouseButtonCallback(m_handle, WindowHandler::GLFWMouseCallback);
    glfwSetCursorPosCallback(m_handle, WindowHandler::GLFWMouseMovementCallback);
    glfwSetScrollCallback(m_handle, WindowHandler::GLFWMouseScrollCallback);
    glfwSetKeyCallback(m_handle, WindowHandler::GLFWKeyCallback);
    glfwSetCharCallback(m_handle, WindowHandler::GLFWCharCallback);

    glfwSetWindowPosCallback(m_handle, WindowHandler::GLFWWindowPosCallback);
    glfwSetWindowSizeCallback(m_handle, WindowHandler::GLFWWindowSizeCallback);
    glfwSetFramebufferSizeCallback(m_handle, WindowHandler::GLFWWindowFramebufferSizeCallback);
    glfwSetWindowContentScaleCallback(m_handle, WindowHandler::GLFWWindowScaleCallback);
    glfwSetWindowFocusCallback(m_handle, WindowHandler::GLFWWindowFocusCallback);
    glfwSetWindowCloseCallback(m_handle, WindowHandler::GLFWWindowCloseCallback);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "[ERROR] failed to initialize glad\n";
        glfwTerminate();

        return false;
    }

    std::cout << "[INFO] Version: "      << glGetString(GL_VERSION)                  << std::endl;
    std::cout << "[INFO] Vendor: "       << glGetString(GL_VENDOR)                   << std::endl;
    std::cout << "[INFO] GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    setMonitor();
    glfwGetWindowPos(m_handle, &m_position.x, &m_position.y);

    return true;
}


// ───────────────────────────────────────────────────────────────────────────
//                             Static Methods
// ───────────────────────────────────────────────────────────────────────────

macOSWindow *macOSWindow::Create()
{
    return Create(Resolution::HD, "Seokhyun Engine", WindowMode::Windowed);
}

macOSWindow *macOSWindow::Create(const std::string &title)
{
    return Create(Resolution::HD, title, WindowMode::Windowed);
}

macOSWindow *macOSWindow::Create(const glm::vec2 &resolution, const std::string &title)
{
    return Create(resolution, title, WindowMode::Windowed);
}

macOSWindow *macOSWindow::Create(const std::string &title, WindowMode windowMode)
{
    return Create(Resolution::HD, title, windowMode);
}

macOSWindow *macOSWindow::Create(const glm::vec2 &resolution, const std::string &title, WindowMode windowMode)
{
    auto window = new macOSWindow();

    window->m_resolution = resolution;
    window->m_title      = title;
    window->m_windowMode = windowMode;

    if (!window->Initialize()) return nullptr;
    return window;
}


// ───────────────────────────────────────────────────────────────────────────
//                              BASIC FUNCTIONS
// ───────────────────────────────────────────────────────────────────────────

bool macOSWindow::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    glfwPollEvents();

    return !glfwWindowShouldClose(m_handle);
}

bool macOSWindow::Close()
{
    return Window::Close();
}

void macOSWindow::setWindowed()
{
    Window::setWindowed();

    float xscale, yscale;
    glfwGetWindowContentScale(m_handle, &xscale, &yscale);

    setResizable(m_resizable);
    glfwSetWindowMonitor(m_handle, nullptr, m_windowedPos.x, m_windowedPos.y, m_windowedSize.x / xscale, m_windowedSize.y / yscale, 0);

    NSWindow *nsWindow = glfwGetCocoaWindow(m_handle);
    if (([nsWindow styleMask] & NSWindowStyleMaskFullScreen) == NSWindowStyleMaskFullScreen)
    {
        [nsWindow toggleFullScreen:nil];
        glfwPollEvents();
    }

    m_windowMode = WindowMode::Windowed;
}

void macOSWindow::setBorderless()
{
    Window::setBorderless();

    m_windowedPos = m_position; m_windowedSize = m_resolution;

    NSWindow *nsWindow = getCocoaWindow();
    if (nsWindow)
    {
        [nsWindow toggleFullScreen:nil];
        glfwPollEvents();
    }

    glfwSetInputMode(m_handle, GLFW_STICKY_KEYS, GLFW_FALSE);
    glfwSetInputMode(m_handle, GLFW_STICKY_KEYS, GLFW_TRUE);

    m_windowMode = WindowMode::Borderless;
}

void macOSWindow::setFullScreen()
{
    Window::setFullScreen();

    m_windowedPos = m_position; m_windowedSize = m_resolution;

    setMonitor();
    glfwSetWindowAttrib(m_handle, GLFW_RESIZABLE, GLFW_FALSE);

    const GLFWvidmode *mode = glfwGetVideoMode(m_monitor);
    glfwSetWindowMonitor(m_handle, m_monitor, 0, 0, mode->width, mode->height, mode->refreshRate);

    m_windowMode = WindowMode::Fullscreen;
}


// ─────────────────────────────────────────────────────────────────────────────
//                                GETTER & SETTER
// ─────────────────────────────────────────────────────────────────────────────

void macOSWindow::setMonitor()
{
    unsigned int monitorIndex = -1;

    NSWindow* nsWindow = getCocoaWindow();
    if (nsWindow)
    {
        NSScreen* currentScreen = [nsWindow screen];
        NSArray<NSScreen*>* screens = [NSScreen screens];

        monitorIndex = [screens indexOfObjectIdenticalTo: currentScreen];
    }

    setMonitor(monitorIndex);
}

void macOSWindow::setMonitor(unsigned int index)
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