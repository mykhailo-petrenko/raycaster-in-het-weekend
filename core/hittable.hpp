//
// Created by Mykhailo Petrenko on 19.02.2022.
//

#ifndef RAYCASTER_IN_HET_WEEKEND_HITTABLE_HPP
#define RAYCASTER_IN_HET_WEEKEND_HITTABLE_HPP

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

using namespace glm;

/**
 * @class Ray
 *
 * Represents a ray in 3D space with an `origin` and a `direction`.
 */
class Ray {
public:
    Ray() = default;

    /**
     * Construct a Ray from two points.
     *
     * @param a {vec3} Origin
     * @param b {vec3} Direction
     */
    Ray(const vec3 &a, const vec3 &b) {
        origin = a;
        direction = normalize(b - a);
    }

    /**
     * Get the Point along the the ray at distance `t` from the `origin` point
     * @param t
     * @return
     */
    vec3 point(float t) const {
        return origin + t * direction;
    }

    // The starting point of the ray.
    vec3 origin{};
    // The normalized direction unit-vector.
    vec3 direction{};
};

/**
 * Ray-object single intersection
 */
struct Hit {
    // Distance along the ray (from ray origin) where intersection happens
    float t;
    // World-space position of the intersection
    vec3 point;
    // Surface normal at the intersection point
    vec3 normal;
};


/**
 * Object that can be "hit" by Ray
 */
class Hittable {
public:
    virtual bool hit(Ray &r, float tMin, float tMax, Hit &hit) = 0;
};

/**
 * A collection of hittable objects (e.g. spheres, planes, etc.)
 */
class HittableList : public Hittable {
public:
    HittableList() = default;

    /**
     * Construct list from a pointer to an array of hittable objects and its size
     *
     * @param l
     * @param n
     */
    HittableList(Hittable **l, int n) {
        list = l;
        size = n;
    }

    Hittable **list{};
    int size{};

    bool hit(Ray &r, float tMin, float tMax, Hit &hit) override {
        Hit tempHit{};

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
