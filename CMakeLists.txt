cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME SeokhyunEngine)
set(CMAKE_CXX_STANDARD 17)

if (APPLE)
    set(CMAKE_CXX_FLAGS "-framework Cocoa -framework IOKit -framework OpenGL -framework Foundation -framework CoreFoundation")

    set(CMAKE_OSX_ARCHITECTURES arm64)
    enable_language(OBJCXX)

    set(SEOKHYUNENGINE_PLATFORM
        SeokhyunEngine/Platform/macOS/macOSAppLauncher.cpp SeokhyunEngine/Platform/macOS/macOSAppLauncher.h
        SeokhyunEngine/Platform/macOS/macOSWindow.mm SeokhyunEngine/Platform/macOS/macOSWindow.h
    )

elseif (WIN32)
    set(SEOKHYUNENGINE_PLATFORM
            SeokhyunEngine/Platform/Windows/WindowsAppLauncher.cpp SeokhyunEngine/Platform/Windows/WindowsAppLauncher.h
            SeokhyunEngine/Platform/Windows/WindowsWindow.cpp SeokhyunEngine/Platform/Windows/WindowsWindow.h
    )

endif ()

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME}

        SampleAppTest/main.cpp
        SampleAppTest/SampleApp.cpp SampleAppTest/SampleApp.h

        SeokhyunEngine/Configuration/WindowMode.h

        SeokhyunEngine/Event/Event.cpp SeokhyunEngine/Event/Event.h
        SeokhyunEngine/Event/EventDispatcher.cpp SeokhyunEngine/Event/EventDispatcher.h
        SeokhyunEngine/Event/EventManager.cpp SeokhyunEngine/Event/EventManager.h
        SeokhyunEngine/Event/Input/KeyBoard/KeyBoardEvent.cpp SeokhyunEngine/Event/Input/KeyBoard/KeyBoardEvent.h
        SeokhyunEngine/Event/Input/KeyBoard/KeyDownEvent.cpp SeokhyunEngine/Event/Input/KeyBoard/KeyDownEvent.h
        SeokhyunEngine/Event/Input/KeyBoard/KeyUpEvent.cpp SeokhyunEngine/Event/Input/KeyBoard/KeyUpEvent.h
        SeokhyunEngine/Event/Input/Mouse/MouseButtonEvent.cpp SeokhyunEngine/Event/Input/Mouse/MouseButtonEvent.h
        SeokhyunEngine/Event/Input/Mouse/MouseDownEvent.cpp SeokhyunEngine/Event/Input/Mouse/MouseDownEvent.h
        SeokhyunEngine/Event/Input/Mouse/MouseUpEvent.cpp SeokhyunEngine/Event/Input/Mouse/MouseUpEvent.h
        SeokhyunEngine/Event/Input/Mouse/MouseMoveEvent.cpp SeokhyunEngine/Event/Input/Mouse/MouseMoveEvent.h
        SeokhyunEngine/Event/Input/Mouse/MouseScrollEvent.cpp SeokhyunEngine/Event/Input/Mouse/MouseScrollEvent.h
        SeokhyunEngine/Event/Window/WindowFocusEvent.cpp SeokhyunEngine/Event/Window/WindowFocusEvent.h
        SeokhyunEngine/Event/Window/WindowMoveEvent.cpp SeokhyunEngine/Event/Window/WindowMoveEvent.h
        SeokhyunEngine/Event/Window/WindowResizeEvent.cpp SeokhyunEngine/Event/Window/WindowResizeEvent.h
        SeokhyunEngine/Event/Window/WindowStateEvent.cpp SeokhyunEngine/Event/Window/WindowStateEvent.h

        SeokhyunEngine/Math/AABB.cpp SeokhyunEngine/Math/AABB.h

        SeokhyunEngine/SeokhyunEngine.h SeokhyunEngine/common.h
        SeokhyunEngine/Launcher.cpp SeokhyunEngine/Launcher.h
        SeokhyunEngine/Application.cpp SeokhyunEngine/Application.h

        SeokhyunEngine/Platform/AppLauncher.cpp SeokhyunEngine/Platform/AppLauncher.h
        SeokhyunEngine/Platform/Window.cpp SeokhyunEngine/Platform/Window.h
        SeokhyunEngine/Platform/WindowHandler.cpp SeokhyunEngine/Platform/WindowHandler.h
        SeokhyunEngine/Platform/RuntimePlatform.h

        ${SEOKHYUNENGINE_PLATFORM}

        SeokhyunEngine/Renderer/OpenGL/Buffer.cpp SeokhyunEngine/Renderer/OpenGL/Buffer.h
        SeokhyunEngine/Renderer/OpenGL/Mesh.cpp SeokhyunEngine/Renderer/OpenGL/Mesh.h
        SeokhyunEngine/Renderer/OpenGL/Program.cpp SeokhyunEngine/Renderer/OpenGL/Program.h
        SeokhyunEngine/Renderer/OpenGL/Shader.cpp SeokhyunEngine/Renderer/OpenGL/Shader.h
        SeokhyunEngine/Renderer/OpenGL/Texture.cpp SeokhyunEngine/Renderer/OpenGL/Texture.h
        SeokhyunEngine/Renderer/OpenGL/VertexArray.cpp SeokhyunEngine/Renderer/OpenGL/VertexArray.h

        SeokhyunEngine/Utility/FileReader.h
        SeokhyunEngine/Utility/Resolution.h
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/SeokhyunEngine)       # SeokhyunEngine 전체를 포함
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/SampleApp)

include(Dependency.cmake)


target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})

target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})


add_dependencies(${PROJECT_NAME} ${DEP_LIST})

if (MSVC)
    target_compile_options(${PROJECT_NAME} PUBLIC /wd4819)
endif()