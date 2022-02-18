//
// Created by Mykhailo Petrenko on 18.02.2022.
//

#ifndef RAYCASTER_IN_HET_WEEKEND_UTIL_H
#define RAYCASTER_IN_HET_WEEKEND_UTIL_H

#include <glm/vec3.hpp>
#include "ray.hpp"

using namespace glm;

typedef vec<3, int, defaultp> color3;

/**
 * Linear interpolation between `from` and `to`.
 * @param from vec3
 * @param to vec3
 * @param k in range from 0 till 1
 * @return vec3
 */
vec3 lerp(vec3 from, vec3 to, float k);
/**
 * Project color from [0:1] to [0:255]
 * @param c
 * @return
 */
int project_color(float c);

/**
 * Project color vector from [0:1] to [0:255]
 * @param c
 * @return
 */
color3 project_color_vector(vec3 c);

#endif //RAYCASTER_IN_HET_WEEKEND_UTIL_H
