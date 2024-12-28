cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME SeokhyunEngine)
set(CMAKE_CXX_STANDARD 17)

if (APPLE)
    set(CMAKE_CXX_FLAGS "-framework Cocoa -framework IOKit -framework OpenGL")

    set(CMAKE_OSX_ARCHITECTURES arm64)
    enable_language(OBJCXX)
endif()

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp)