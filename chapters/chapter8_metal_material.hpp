//
// Created by Mykhailo Petrenko on 17/09/2025.
//

#ifndef RAYCASTER_IN_HET_WEEKEND_CHAPTER8_METAL_MATERIAL_HPP
#define RAYCASTER_IN_HET_WEEKEND_CHAPTER8_METAL_MATERIAL_HPP

#include "chapter8_metal_material.hpp"
#include "../bitmap/bitmap_image.hpp"

namespace chapter8 {
    void chapter8_metal_material(const std::string& out_path) {
        const unsigned int NX = 256;
        const unsigned int NY = 256;

        bitmap_image image(NX, NY);

        for (unsigned int x = 0; x < NX; ++x) {
            for (unsigned int y = 0; y < NY; ++y) {
                image.set_pixel(x, y, x, y, 0);
            }
        }

        image.save_image(out_path);
        SPDLOG_INFO(out_path);
    }
} // chapter8

#endif //RAYCASTER_IN_HET_WEEKEND_CHAPTER8_METAL_MATERIAL_HPP
