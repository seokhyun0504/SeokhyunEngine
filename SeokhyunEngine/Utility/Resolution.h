#ifndef __RESOLUTION_H__
#define __RESOLUTION_H__

#include "common.h"

/**
 * @brief Collection of Standard Resolutions
 * @tag PreDefinations
 */
namespace Resolution
{
    static const glm::ivec2 VGA       { glm::ivec2(640, 480) };
    static const glm::ivec2 SVGA      { glm::ivec2(800, 600) };
    static const glm::ivec2 XGA       { glm::ivec2(1024, 768) };
    static const glm::ivec2 WXGA      { glm::ivec2(1280, 800) };
    static const glm::ivec2 WXGAH     { glm::ivec2(1366, 768) };
    static const glm::ivec2 WSXGA     { glm::ivec2(1440, 900) };
    static const glm::ivec2 WUXGA     { glm::ivec2(1920, 1200) };
    static const glm::ivec2 WQXGA     { glm::ivec2(2560, 1600) };
    static const glm::ivec2 WQHD      { glm::ivec2(2560, 1440) };
    static const glm::ivec2 WQUXGA    { glm::ivec2(3840, 2400) };
    static const glm::ivec2 WQUHD     { glm::ivec2(3840, 2160) };
    static const glm::ivec2 WQUHD2    { glm::ivec2(5120, 2880) };
    static const glm::ivec2 WQUHD3    { glm::ivec2(7680, 4320) };

    static const glm::ivec2 SD        { glm::ivec2(720, 480) };
    static const glm::ivec2 HD        { glm::ivec2(1280, 720) };
    static const glm::ivec2 HDPLUS    { glm::ivec2(1600, 900) };
    static const glm::ivec2 FHD       { glm::ivec2(1920, 1080) };
    static const glm::ivec2 QHD       { glm::ivec2(2560, 1440) };
    static const glm::ivec2 UHD       { glm::ivec2(3840, 2160) };
    static const glm::ivec2 UHD4K     { glm::ivec2(4096, 2160) };
    static const glm::ivec2 UHD8K     { glm::ivec2(7680, 4320) };

    static const glm::ivec2 UNLIMITED { glm::ivec2(-1, -1)};
};

#endif //__RESOLUTION_H__