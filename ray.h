//
// Created by Mykhailo Petrenko on 17.02.2022.
//

#ifndef RAYCASTER_IN_HET_WEEKEND_RAY_H
#define RAYCASTER_IN_HET_WEEKEND_RAY_H
#include <glm/vec3.hpp>
using namespace glm;

class Ray {
    Ray();
    Ray(const vec3 &a, const vec3 &b);
    vec3 point(float t);
    vec3 origin;
    vec3 direction;
};


#endif //RAYCASTER_IN_HET_WEEKEND_RAY_H
