//
// Created by Mykhailo Petrenko on 21.02.2022.
//

#ifndef RAYCASTER_IN_HET_WEEKEND_CAMERA_H
#define RAYCASTER_IN_HET_WEEKEND_CAMERA_H
#import "hittable.hpp"
class Camera {
public:
    Camera() {
        origin = vec3(0., 0., 0.);
        width = vec3(2., 0., 0.);
        height = vec3(0., 2., 0.);
        lower_left = vec3(-1., -1, -1);
    }

    Ray getRay(float u, float v) {
        return Ray(origin, lower_left + u * width + v * height);
    }

    vec3 origin;
    vec3 width;
    vec3 height;
    vec3 lower_left;
};

#endif //RAYCASTER_IN_HET_WEEKEND_CAMERA_H
