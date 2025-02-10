#ifndef __RUNTIMEINFO_H__
#define __RUNTIMEINFO_H__

#include <iostream>

namespace RuntimeInfo
{
    #define OS_UNKNOWN              0
    #define OS_WINDOWS              1
    #define OS_MACOS                2
    #define OS_LINUX                3
    #define OS_IOS                  4
    #define OS_ANDROID              5

    #define OS_IOS_SIMULATOR        6

    #define PLATFORM_UNKNOWN        0
    #define PLATFORM_DESKTOP        1
    #define PLATFORM_MOBILE         2
    #define PLATFORM_APPLE          3

    #define ARCHITECTURE_UNKNOWN    0
    #define ARCHITECTURE_X86        1
    #define ARCHITECTURE_X86_64     2
    #define ARCHITECTURE_ARM64      3

    #define GRAPHICSAPI_UNKNOWN     0
    #define GRAPHICSAPI_OPENGL      1
    #define GRAPHICSAPI_OPENGLES    2
    #define GRAPHICSAPI_VULKAN      3
    #define GRAPHICSAPI_METAL       4
    #define GRPAHICSAPI_DIRECT      5

    #define OS_INFO                 OS_UNKNOWN
    #define PLATFORM_INFO           PLATFORM_UNKNOWN
    #define GRAPHICSAPI_INFO        GRAPHICSAPI_UNKOWN

    enum OS
    {
        Unknown_OS =    0,

        /* Desktop & Mobile */
        Windows =       1,
        macOS =         2,
        Linux =         3,
        iOS =           4,
        Android =       5,

        /* Simulator */
        iOS_Simulator = 6,

        /* Console Device */

    };

    enum Architecture
    {
        Unknown_Architecture,

        x86,
        x86_64,
        ARM64
    };

    enum GraphicsAPI
    {
        Unknown_GraphicsAPI,

        OpenGL,
        OpenGLES,
        Vulkan,
        Metal,
        Direct
    };


#pragma mark - OS & Architecture


    /*
     Define Windows
     */
    #ifdef _WIN32
        #undef OS_INFO
            #define OS_INFO OS_WINDOWS
            const OS RuntimeOS = Windows;

                #if _WIN64
                    const Architecture RuntimeArch = x86_64;
                #else
                    const Architecture RuntimeArch = x86;
                #endif
    #endif

    /*
     Define Apple
     */
    #ifdef __APPLE__


#include <TargetConditionals.h>

        #if TARGET_IPHONE_SIMULATOR
            #undef OS_INFO
                    #define OS_INFO OS_IOS_SIMULATOR
                    const OS RuntimeOS = iOS_Simulator;

        #elif TARGET_OS_IPHONE
            #undef OS_INFO
                    #define OS_INFO OS_IOS
                    const OS RuntimeOS = iOS;

        #elif TARGET_OS_MAC
            #undef OS_INFO
            #define OS_INFO OS_MACOS
            const OS RuntimeOS = macOS;

            #if TARGET_CPU_X86_64
                #undef ARCHITECTURE_INFO
                #define ARCHITECTURE_INFO ARCHITECTURE_X86_64
                const Architecture RuntimeArch = x86_64; // Intel
            #elif TARGET_CPU_ARM64
                #undef ARCHITECTURE_INFO
                #define ARCHITECTURE_INFO ARCHITECTURE_ARM64
                const Architecture RuntimeArch = ARM64; // Apple Silicon
            #endif


        #endif

    #endif

    /*
     Define Linux
     */
#ifdef __linux__
    #undef OS_INFO
        #define OS_INFO OS_LINUX
        const OS RuntimeOS = Linux;
#endif

    /*
     Define Android
     */
#ifdef _ANDROID_
    #undef OS_INFO
        #define OS_INFO OS_ANDROID
        const OS RuntimeOS = Android;
#endif


//    #if (PLATFORM_INFO == PLATFORM_UNKNOWN)
//        throw new std::runtime_error();
//    #endif


#pragma mark - Platform


    const bool Desktop = (RuntimeOS == Windows || RuntimeOS == macOS || RuntimeOS == Linux);

    const bool Mobile  = (RuntimeOS == iOS || RuntimeOS == Android);

    const bool Apple   = (RuntimeOS == macOS || RuntimeOS == iOS);


    /*
     Define desktop platform
     */
    #if (OS_INFO == OS_WINDOWS) || (OS_INFO == OS_MACOS) || (OS_INFO == OS_LINUX)
        #undef PLATFORM_INFO
        #define PLAYFORM_INFO PLATFORM_DESKTOP
#endif

    /*
     Define mobile platform
     */
    #if (OS_INFO == OS_IOS) || (OS_INFO == OS_ANDROID)
        #undef PLAYFORM_INFO
        #define PLAYFORM_INFO PLAYFORM_MOBILE
    #endif

    /*
     Define apple system
     */
    #if (OS_INFO == OS_IOS) || (OS_INFO == OS_MACOS)
        #undef PLATFORM_INFO
        #define PLATFORM_INFO PLATFORM_APPLE
    #endif


#pragma mark - GraphicsAPI


    /*
     Define OpenGL Types
    */
    #if (PLATFORM_INFO == PLATFORM_DESKTOP || OS_INFO == OS_MACOS)
        #undef GRAPHICSAPI_OPENGLES
    #elif (PLATFORM_INFO == PLATFORM_MOBILE)
        #undef GRAPHICSAPI_OPENGL
    #endif


    /*
     Define Using Direct Series
    */
    #if (OS_INFO != OS_WINDOWS)
        #undef GRAPHICSAPI_DIRECT
    #endif

    /*
     Define Apple Supports
    */
    #if (PLATFORM_INFO == PLATFORM_APPLE)
        #undef GRAPHICSAPI_VULKAN
    #else
        #undef GRAPHICSAPI_METAL
    #endif


    /// exception
    // #if (PLATFORM_INFO == PLATFORM_UNKNOWN)
    //     throw new std::runtime_error();
    // #endif
};

#endif //__RUNTIMEINFO_H__
