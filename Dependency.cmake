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

# glm
ExternalProject_Add(
    dep_glm
    GIT_REPOSITORY "https://github.com/g-truc/glm"
    GIT_TAG "1.0.1"
    GIT_SHALLOW 1
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    TEST_COMMAND ""
    INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_BINARY_DIR}/dep_glm-prefix/src/dep_glm/glm
        ${DEP_INSTALL_DIR}/include/glm
    )
set(DEP_LIST ${DEP_LIST} dep_glm)