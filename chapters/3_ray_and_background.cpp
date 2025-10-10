//
// Created by Mykhailo Petrenko on 18.02.2022.
//
#include <iostream>
#include "../core/util.h"
#include "../bitmap/bitmap_image.hpp"

void chapter3_ray_and_background() {
    std::string out_path("./artifacts/chapter3.bmp");

    const int NX = 256;
    const int NY = 256;

    bitmap_image image(NX, NY);

    color3 rgb;
    Ray ray;
    vec3 origin = vec3(0.,0.,0.);
    vec3 width = vec3(2.,0.,0.);
    vec3 height = vec3(0.,2.,0.);
    vec3 lower_left = vec3(-1., -1, -1);

    for (int y = 0; y < NY; y++) {
        for (int x = 0; x < NX; x++) {
            float u = float(x) / float(NX);
            float v = float(NY - 1 - y) / float(NY);

            ray = Ray(origin, lower_left + u*width + v*height);

            rgb = color(ray);

            image.set_pixel(x, y, rgb[0], rgb[1], rgb[2]);
        }
    }

    image.save_image(out_path);
}
