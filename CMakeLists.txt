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

        SeokhyunEngine/Math/AABB.cpp SeokhyunEngine/Math/AABB.h

        SeokhyunEngine/SeokhyunEngine.h SeokhyunEngine/common.h
        SeokhyunEngine/Launcher.h SeokhyunEngine/Launcher.cpp
        SeokhyunEngine/Application.cpp SeokhyunEngine/Application.h

        SeokhyunEngine/Platform/AppLauncher.cpp SeokhyunEngine/Platform/AppLauncher.h
        SeokhyunEngine/Platform/Window.cpp SeokhyunEngine/Platform/Window.h
        SeokhyunEngine/Platform/WindowHandler.cpp SeokhyunEngine/Platform/WindowHandler.h
        SeokhyunEngine/Platform/RuntimePlatform.h

        ${SEOKHYUNENGINE_PLATFORM}

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