#include <iostream>

#include "Platform/Window.h"

int main(const int argc, const char ** argv)
{
    Window *window = Window::Create("Test Window!", WindowMode::Windowed);
    while (window->Update()) { }

    delete window;
    return 0;
}