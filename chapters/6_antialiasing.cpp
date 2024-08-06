//
// Created by Mykhailo Petrenko on 18.02.2022.
//
#include <iostream>
#include <fstream>
#include "../core/util.h"
#include "../core/camera.h"

namespace chapter6 {

    /**
     * Surface Normals
     */
    void chapter6_antialiasing() {
        std::ofstream image;
        image.open("./artifacts/chapter6.ppm");

        int NX = 256;
        int NY = 256;

        int NS = 20;

        image << "P3\n" << NX << " " << NY << "\n255\n";

        color3 rgb;
        Ray ray;
        auto camera = new Camera();

        Hittable *list[4];
        list[0] = new Sphere(vec3(0.5, 0, -1), 0.25);
        list[1] = new Sphere(vec3(-0.5, 0.5, -0.75), 0.25);
        list[2] = new Sphere(vec3(0., -0.5, -2), 0.25);
        list[3] = new Sphere(vec3(0., 0., -1), 0.15);

        auto *world = new HittableList(list, 4);
        Hit hit;

        for (int y = NY - 1; y >= 0; y--) {
            for (int x = 0; x < NX; x++) {
                vec3 color = vec3(0., 0., 0.);

                for (int i = 0; i < NS; i++) {
                    float u = float(x + drand48()) / float(NX);
                    float v = float(y + drand48()) / float(NY);

                    ray = camera->getRay(u, v);

                    if (world->hit(ray, 0.00001, MAXFLOAT, hit)) {
                        color += project_normal_to_color(hit.normal);
                    } else {
                        color += lerp(WHITE, BLUE, (ray.direction.y + 1.) / 2);
                    }
                }

                color /= float(NS);

                color3 rgb = project_color_vector(color);
                image << rgb[0] << " " << rgb[1] << " " << rgb[2] << "\n";
            }
        }


        image.close();
    }

}