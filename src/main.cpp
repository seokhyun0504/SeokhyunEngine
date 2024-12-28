#include <iostream>

#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

int main(const int argc, const char ** argv)
{
    if (!glfwInit())
    {
        std::cerr << "ERROR: Failed to initialize GLFW" << std::endl;
        return -1;
    }

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,    GLFW_TRUE);
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, GLFW_TRUE);
#endif

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);


    GLFWwindow *window = glfwCreateWindow(1280, 720, "OpenGL Window", nullptr, nullptr);

    if (window == nullptr)
    {
        std::cerr << "ERROR: GLFWwindow was NOT Created!\n";
        exit(-1);
    }


    glfwSetWindowSizeLimits(window, 128, 128, GLFW_DONT_CARE, GLFW_DONT_CARE);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "failed to initialize glad\n";
        glfwTerminate();

        exit(-1);
    }

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);

        glClearColor(0.2f, 0.1f, 0.3f, 1.0f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}