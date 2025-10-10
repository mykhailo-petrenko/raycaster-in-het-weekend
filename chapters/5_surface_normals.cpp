//
// Created by Mykhailo Petrenko on 18.02.2022.
//
#include <iostream>
#include <fstream>
#include "../core/util.h"
#include "../bitmap/bitmap_image.hpp"

namespace chapter5 {
    bool is_hits_sphere(Ray r, Sphere sphere) {
        float a = dot(r.direction, r.direction);
        float b = 2. * dot(r.direction, r.origin - sphere.center);
        float c = dot(r.origin - sphere.center, r.origin - sphere.center) - (sphere.radius * sphere.radius);

        return quad_equation_has_solution(a, b, c);
    }

    vec3 intersection_normal(Ray r, Sphere sphere) {
        float a = dot(r.direction, r.direction);
        float b = 2. * dot(r.direction, r.origin - sphere.center);
        float c = dot(r.origin - sphere.center, r.origin - sphere.center) - (sphere.radius * sphere.radius);

        vec<2, float> x = quad_equation(a, b, c);

        vec3 normal = normalize(r.point(x[0]) - sphere.center);

        return normal;
    }

    /**
     * Surface Normals
     */
    void chapter5_surface_normals() {
        std::string out_path("./artifacts/chapter5.bmp");


        int NX = 256;
        int NY = 256;

        bitmap_image image(NX, NY);

        color3 rgb;
        Ray ray;
        vec3 origin = vec3(0., 0., 0.);
        vec3 width = vec3(2., 0., 0.);
        vec3 height = vec3(0., 2., 0.);
        vec3 lower_left = vec3(-1., -1, -1);

        Hittable *list[4];
        list[0] = new Sphere(vec3(0.5, 0, -1), 0.25);
        list[1] = new Sphere(vec3(-0.5, 0.5, -0.75), 0.25);
        list[2] = new Sphere(vec3(0., -0.5, -2), 0.25);
        list[3] = new Sphere(vec3(0., 0., -1), 0.15);

        auto *world = new HittableList(list, 4);

        for (int y = NY - 1; y >= 0; y--) {
            for (int x = 0; x < NX; x++) {
                float u = float(x) / float(NX);
                float v = float(y) / float(NY);

                ray = Ray(origin, lower_left + u * width + v * height);

                vec3 color = vec3(0., 0., 0.);

                Hit hit;

                if (world->hit(ray, 0., MAXFLOAT, hit)) {
                    color = project_normal_to_color(hit.normal);
                } else {
                    color = lerp(WHITE, BLUE, (ray.direction.y + 1.) / 2);
                }

                color3 rgb = project_color_vector(color);
                image.set_pixel(x, NY-y-1, rgb[0], rgb[1], rgb[2]);
            }
        }


        image.save_image(out_path);
    }

}