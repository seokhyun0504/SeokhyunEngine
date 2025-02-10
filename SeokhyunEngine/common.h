#ifndef __COMMON_H__
#define __COMMON_H__

#include "Platform/RuntimePlatform.h"

// ────────────── C++ STANDARD ──────────────
#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include <optional>


// ───────────────── OpenGL ─────────────────
#include <glad/glad.h>


// ────────────────── GLFW ───────────────────
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

#if (OS_INFO == OS_WINDOWS)
#ifndef GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#ifndef GLFW_EXPOSE_NATIVE_WGL
#define GLFW_EXPOSE_NATIVE_WGL
#endif
#include <GLFW/glfw3native.h>
#include <windows.h>
#endif


// ─────────────────── GLM ───────────────────
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>


#endif // __COMMON_H__