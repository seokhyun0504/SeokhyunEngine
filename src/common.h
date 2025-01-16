#ifndef __COMMON_H__
#define __COMMON_H__

#include "RuntimePlatform.h"

#include <iostream>
#include <memory>
#include <string>
#include <optional>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#if (OS_INFO == OS_MACOS)
#ifndef GLFW_EXPOSE_NATIVE_NSGL
#define GLFW_EXPOSE_NATIVE_NSGL
#endif
#ifndef GLFW_EXPOSE_NATIVE_COCOA
#define GLFW_EXPOSE_NATIVE_COCOA
#endif
#include <GLFW/glfw3native.h>
#endif

// #if (OS_INFO == TARGET_OS_WIN32)
// #ifndef GLFW_EXPOSE_NATIVE_WGL
// #define GLFW_EXPOSE_NATIVE_WGL



#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>


#endif // __COMMON_H__