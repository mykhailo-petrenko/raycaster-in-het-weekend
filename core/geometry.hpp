//
// Created by Mykhailo Petrenko on 17.02.2022.
//

#ifndef RAYCASTER_IN_HET_WEEKEND_RAY_HPP
#define RAYCASTER_IN_HET_WEEKEND_RAY_HPP
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include "hittable.hpp"
using namespace glm;

class Sphere: public Hittable {
public:
    Sphere() {}

    Sphere(const vec3 c, const float r) {
        center = c;
        radius = r;
    }

    vec3 center;
    float radius;

    bool hit(Ray &r, float tMin, float tMax, Hit &hit) {
        vec3 oc = r.origin - center;
        float a = dot(r.direction, r.direction);
        float b = 2. * dot(r.direction, oc);
        float c = dot(oc, oc) - (radius * radius);

        float D = b * b - (4 * a * c);

        if (D < 0.) {
            return false;
        }

        D = sqrt(D);

        float t = (-b - D) / (2 * a);

        if (t > tMin && t < tMax) {
            hit.t = t;
            hit.point = r.point(t);
            hit.normal = normalize(hit.point - center);
            return true;
        }

        t = (-b + D) / (2 * a);

        if (t > tMin && t < tMax) {
            hit.t = t;
            hit.point = r.point(t);
            hit.normal = normalize(hit.point - center);
        }

        return false;
    }
};

#endif //RAYCASTER_IN_HET_WEEKEND_RAY_HPP
