#include "AppLauncher.h"

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
    m_window = createWindow();

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

    while (!m_window->windowShouldClose())
    {
        m_window->Update();
        m_window->pollEvents();
    }

    m_window->Close();
    return 0;
}

