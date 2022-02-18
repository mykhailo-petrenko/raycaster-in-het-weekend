//
// Created by Mykhailo Petrenko on 17.02.2022.
//

#ifndef RAYCASTER_IN_HET_WEEKEND_RAY_HPP
#define RAYCASTER_IN_HET_WEEKEND_RAY_HPP
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include "util.h"
using namespace glm;

class Ray {
public:
    Ray() {}
    Ray(const vec3 &a, const vec3 &b) {
        origin = a;
        direction = normalize(b - a);
    }

    vec3 point(float t) {
        return origin + t * direction;
    }

    vec3 origin;
    vec3 direction;
};


#endif //RAYCASTER_IN_HET_WEEKEND_RAY_HPP
