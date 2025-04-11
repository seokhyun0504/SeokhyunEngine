#include "AppLauncher.h"

#include "Application.h"
#include "Window.h"

AppLauncher::AppLauncher() : m_window(nullptr)
{

}

AppLauncher::~AppLauncher()
{
    if (m_window)
        m_window = nullptr;
}

bool AppLauncher::setWindow(std::string appName) // todo: .settings 관련 기능이 생길 경우 인자를 받아 window 생성
{
    m_window = createWindow(appName);

    if (!m_window)
    {
        std::cout << "[ERROR] AppLauncher couldn't create window!" << std::endl;
        return false;
    }

    m_window->setTitle(appName);
    return true;
}


int AppLauncher::run(Application *app)
{
    if (!setWindow(app->getName())) return -1;

    app->OnInit();

    while (!m_window->windowShouldClose())
    {
        m_window->Update();
        app->OnUpdate();

        m_window->swapBuffers();
    }

    m_window->Close();
    return 0;
}

