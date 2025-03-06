#ifndef __APPLAUNCHER_H__
#define __APPLAUNCHER_H__

#include <iostream>

#include "common.h"

#include "Application.h"
#include "Platform/Window.h"

class Window;

class AppLauncher
{

private:

    Window *m_window;

    virtual Window* createWindow(std::string &appName) = 0;
    bool setWindow(std::string appName); // todo: 설정 관련 기능이 생길 경우 관련 클래스 인자를 받아 window 생성


public:

    // ─────────────── CONSTRUCTOR ──────────────
    AppLauncher();
    virtual ~AppLauncher();


    // ───────────── BASIC FUNCTIONS ────────────
    int run(Application *app);
};


#endif //__APPLAUNCHER_H__
