//
// Created by Mykhailo Petrenko on 18.02.2022.
//
#include <iostream>
#include <fstream>
#include "../util.h"

void chapter3_ray_and_background() {
    std::ofstream image;
    image.open("./artifacts/chapter3.ppm");

    int NX = 256;
    int NY = 256;

    image << "P3\n" << NX << " " << NY << "\n255\n";

    color3 rgb;
    Ray ray;
    vec3 origin = vec3(0.,0.,0.);
    vec3 width = vec3(2.,0.,0.);
    vec3 height = vec3(0.,2.,0.);
    vec3 lower_left = vec3(-1., -1, -1);

    for (int y = NY - 1; y >= 0; y--) {
        for (int x = 0; x < NX; x++) {
            float u = float(x) / float(NX);
            float v = float(y) / float(NY);

            ray = Ray(origin, lower_left + u*width + v*height);

            rgb = color(ray);

            image << rgb[0] << " " << rgb[1] << " " << rgb[2] << "\n";
        }
    }


    image.close();
}
