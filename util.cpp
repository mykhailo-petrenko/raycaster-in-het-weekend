//
// Created by Mykhailo Petrenko on 18.02.2022.
//
#include "util.h"

vec3 lerp(const vec3 from, const vec3 to, float k) {
    return (1 - k) * from + k * to;
}

int project_color(float c) {
    return int(255.99 * c);
}

color3 project_color_vector(vec3 c) {
    return color3(
            project_color(c[0]),
            project_color(c[1]),
            project_color(c[2])
            );
}
