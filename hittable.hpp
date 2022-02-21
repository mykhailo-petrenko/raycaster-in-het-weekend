//
// Created by Mykhailo Petrenko on 19.02.2022.
//

#ifndef RAYCASTER_IN_HET_WEEKEND_HITTABLE_HPP
#define RAYCASTER_IN_HET_WEEKEND_HITTABLE_HPP

#include <glm/vec3.hpp>
#include "geometry.hpp"

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


struct Hit {
    float t;
    vec3 point;
    vec3 normal;
};

class Hittable {
public:
    virtual bool hit(Ray &r, float tMin, float tMax, Hit &hit) = 0;
};

class HittableList : Hittable {
public:
    HittableList() {}
    HittableList(Hittable **l, int n) {
        list = l;
        size = n;
    }

    Hittable **list;
    int size;

    bool hit(Ray &r, float tMin, float tMax, Hit &hit) override {
        Hit tempHit;

        bool isHitAnything = false;
        float closest = tMax;

        for (int i = 0; i < size; i++) {
            if (list[i]->hit(r, tMin, closest, tempHit)) {
                isHitAnything = true;
                closest = tempHit.t;
                hit = tempHit;
            }
        }

        return isHitAnything;
    }
};


#endif //RAYCASTER_IN_HET_WEEKEND_HITTABLE_HPP
