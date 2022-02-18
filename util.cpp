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

bool quad_equation_has_solution(float a, float b, float c) {
    float D = b*b - (4*a*c);

    return (D >= 0);
}

vec<2, float> quad_equation(float a, float b, float c) {
    float D = sqrt(b*b - (4*a*c));

    return vec<2, float>(
            (-b + D) / (2 * a),
            (-b - D) / (2 * a)
            );
}

color3 color(Ray r) {
    double t = (r.direction.y + 1.) / 2.;
    vec3 c = lerp(WHITE, BLUE, t);

    return project_color_vector(c);
}
