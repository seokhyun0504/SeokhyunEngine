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


include(Dependency.cmake)


target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})


add_dependencies(${PROJECT_NAME} ${DEP_LIST})

if (MSVC)
    target_compile_options(${PROJECT_NAME} PUBLIC /wd4819)
endif()