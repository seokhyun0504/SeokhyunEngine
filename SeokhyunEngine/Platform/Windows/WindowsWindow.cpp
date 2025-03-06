#include <vector>
#include "WindowsWindow.h"

// ─────────────────────────────────────────────────────────────────────────────
//                              CONSTRUCTOR & DESTRUCTOR
// ─────────────────────────────────────────────────────────────────────────────

WindowsWindow::WindowsWindow()
{

}


WindowsWindow::~WindowsWindow()
{

}


// ─────────────────────────────────────────────────────────────────────────────
//                               PRIVATE METHODS
// ─────────────────────────────────────────────────────────────────────────────

bool WindowsWindow::Initialize()
{
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

WindowsWindow *WindowsWindow::Create()
{
    return Create(Resolution::HD, "Seokhyun Engine", WindowMode::Windowed);
}

WindowsWindow *WindowsWindow::Create(const std::string &title)
{
    return Create(Resolution::HD, title, WindowMode::Windowed);
}

WindowsWindow *WindowsWindow::Create(const glm::vec2 &resolution, const std::string &title)
{
    return Create(resolution, title, WindowMode::Windowed);
}

WindowsWindow *WindowsWindow::Create(const std::string &title, WindowMode windowMode)
{
    return Create(Resolution::HD, title, windowMode);
}

WindowsWindow *WindowsWindow::Create(const glm::vec2 &resolution, const std::string &title, WindowMode windowMode)
{
    auto window = new WindowsWindow();

    window->m_resolution = resolution;
    window->m_title      = title;
    window->m_windowMode = windowMode;


    if (!window->Initialize()) return nullptr;
    return window;
}


// ───────────────────────────────────────────────────────────────────────────
//                              BASIC FUNCTIONS
// ───────────────────────────────────────────────────────────────────────────

bool WindowsWindow::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    glfwSwapBuffers(m_handle);

    return !glfwWindowShouldClose(m_handle);
}

bool WindowsWindow::Close()
{
    return true;
}

void WindowsWindow::setWindowed()
{
    Window::setWindowed();

    setResizable(m_resizable);

    glfwSetWindowAttrib(m_handle, GLFW_DECORATED, GLFW_TRUE);
    glfwSetWindowMonitor(m_handle, nullptr, m_windowedPos.x, m_windowedPos.y, m_windowedSize.x, m_windowedSize.y, 0);

    m_position = m_windowedPos;
    m_resolution = m_windowedSize;

    m_windowMode = WindowMode::Windowed;
}

void WindowsWindow::setBorderless()
{
    Window::setBorderless();

    setMonitor();
    if (m_windowMode == WindowMode::Windowed)
    {
        m_windowedPos  = m_position;
        m_windowedSize = m_resolution;
    }

    int monitorPosX, monitorPosY;
    glfwGetMonitorPos(m_monitor, &monitorPosX, &monitorPosY);

    const GLFWvidmode *mode = glfwGetVideoMode(m_monitor);

    glfwSetWindowPos(m_handle, monitorPosX, monitorPosY);
    glfwSetWindowSize(m_handle, mode->width, mode->height);

    glfwSetWindowAttrib(m_handle, GLFW_DECORATED, GLFW_FALSE);


    HWND hWnd = glfwGetWin32Window(m_handle);
    if (hWnd)
    {
        LONG style = GetWindowLong(hWnd, GWL_STYLE);

        style &= ~(WS_OVERLAPPEDWINDOW);
        SetWindowLong(hWnd, GWL_STYLE, style);

        SetWindowPos(hWnd, nullptr, monitorPosX, monitorPosY, mode->width, mode->height, SWP_FRAMECHANGED | SWP_NOZORDER);
    }

    m_windowMode = WindowMode::Borderless;
}

void WindowsWindow::setFullScreen()
{
    Window::setFullScreen();

    setMonitor();
    if (m_windowMode == WindowMode::Windowed)
    {
        m_windowedPos  = m_position;
        m_windowedSize = m_resolution;
    }

    glfwSetWindowAttrib(m_handle, GLFW_RESIZABLE, GLFW_FALSE);

    const GLFWvidmode *mode = glfwGetVideoMode(m_monitor);
    glfwSetWindowMonitor(m_handle, m_monitor, 0, 0, mode->width, mode->height, mode->refreshRate);

    m_windowMode = WindowMode::Fullscreen;
}


// ─────────────────────────────────────────────────────────────────────────────
//                                GETTER & SETTER
// ─────────────────────────────────────────────────────────────────────────────
void WindowsWindow::setMonitor()
{
    unsigned int monitorIndex = -1;

    HWND hwnd = getWin32Window();
    HMONITOR targetMonitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);

    std::vector<HMONITOR> hmonitors;
    EnumDisplayMonitors
    (
        nullptr,
        nullptr,
        [] (HMONITOR hMonitor, HDC, LPRECT, LPARAM lParam)
        {
            auto monitors = reinterpret_cast<std::vector<HMONITOR>*>(lParam);
            monitors->push_back(hMonitor);
            return TRUE;
        },
        reinterpret_cast<LPARAM>(&hmonitors)
    );

    for (unsigned int i = 0; i < hmonitors.size(); ++i)
    {
        if (hmonitors[i] == targetMonitor)
        {
            monitorIndex = i;
            break;
        }
    }

    setMonitor(monitorIndex);
}

void WindowsWindow::setMonitor(unsigned int index)
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