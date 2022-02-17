//
// Created by Mykhailo Petrenko on 17.02.2022.
//
#include <glm/vec3.hpp>
#include "ray.h"

using namespace glm;

class Ray {
    public:
        Ray() {}
        Ray(const vec3 &a, const vec3 &b) {
            origin = a;
            direction = b;
        }

        vec3 point(float t) {
            return origin + t * direction;
        }

        vec3 origin;
        vec3 direction;
};