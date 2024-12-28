include(ExternalProject)

set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)

# glfw
ExternalProject_Add(
    dep_glfw
    GIT_REPOSITORY "https://github.com/glfw/glfw.git"
    GIT_TAG "3.3.8"
    GIT_SHALLOW 1
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
        -DGLFW_BUILD_EXAMPLES=OFF
        -DGLFW_BUILD_TESTS=OFF
        -DGLFW_BUILD_DOCS=OFF
    TEST_COMMAND ""
    )
set(DEP_LIST ${DEP_LIST} dep_glfw)
if(MSVC)
    # set(DEP_LIBS ${DEP_LIBS} glfw3$<$<<CONFIG:Debug>:d>)
else()
    set(DEP_LIBS ${DEP_LIBS} glfw3)
endif()

# glad
ExternalProject_Add(
        dep_glad
        GIT_REPOSITORY "https://github.com/Dav1dde/glad"
        GIT_TAG "v0.1.34"
        GIT_SHALLOW 1
        UPDATE_COMMAND ""
        PATCH_COMMAND ""
        CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
        -DGLAD_INSTALL=ON
        TEST_COMMAND ""
)
set(DEP_LIST ${DEP_LIST} dep_glad)
if(MSVC)
    # set(DEP_LIBS ${DEP_LIBS} glfw3$<$<<CONFIG:Debug>:d>)
else()
    set(DEP_LIBS ${DEP_LIBS} glad)
endif()