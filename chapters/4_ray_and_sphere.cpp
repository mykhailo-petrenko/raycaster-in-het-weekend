//
// Created by Mykhailo Petrenko on 18.02.2022.
//
#include <iostream>
#include <fstream>
#include "../util.h"


/**
 * If the ray intersects - returns k > 0;
 *  returning value `k` is in range from 0 to 1
 *  if the distance between two intersection points closer to diameter k closer to 1
 *  if the distance between two intersection points close to 0 - then k is going to 0
 * @param r ray
 * @param sphere sphere
 * @return
 */
float ray_with_sphere_intersection_depth(Ray r, Sphere sphere) {
    float a = dot(r.direction, r.direction);
    float b = 2. * dot(r.direction, r.origin - sphere.center);
    float c = dot(r.origin - sphere.center, r.origin - sphere.center) - (sphere.radius * sphere.radius);

    if (!quad_equation_has_solution(a, b, c)) {
        return 0;
    }

    vec<2, float> x = quad_equation(a, b, c);

    return (x[0] - x[1]) / (sphere.radius * 2.);
 }

/**
 * Add the few spheres.
 * When the ray intersects the sphere - just mix the color with background.
 * The sphere color amount depends on how far from center ray intersects the sphere.
*/
void chapter4_ray_and_sphere() {
    std::ofstream image;
    image.open("./artifacts/chapter4.ppm");

    int NX = 256;
    int NY = 256;

    image << "P3\n" << NX << " " << NY << "\n255\n";

    color3 rgb;
    Ray ray;
    vec3 origin = vec3(0.,0.,0.);
    vec3 width = vec3(2.,0.,0.);
    vec3 height = vec3(0.,2.,0.);
    vec3 lower_left = vec3(-1., -1, -1);

    auto sphere1 = Sphere(vec3(0.5, 0, -1), 0.25);
    auto sphere2 = Sphere(vec3(-0.5, 0.5, -0.75), 0.25);
    auto sphere3 = Sphere(vec3(0., 0., -1), 0.15);

    for (int y = NY - 1; y >= 0; y--) {
        for (int x = 0; x < NX; x++) {
            float u = float(x) / float(NX);
            float v = float(y) / float(NY);

            ray = Ray(origin, lower_left + u*width + v*height);

            double t = (ray.direction.y + 1.) / 2.;
            vec3 c = lerp(WHITE, BLUE, t);

            float k1 = ray_with_sphere_intersection_depth(ray, sphere1);
            c = lerp(c, vec3(1.,0.,0.), k1);

            float k2 = ray_with_sphere_intersection_depth(ray, sphere2);
            c = lerp(c, vec3(0.,1.,0.), k2);

            float k3 = ray_with_sphere_intersection_depth(ray, sphere3);
            c = lerp(c, vec3(0.,0.,1.), k3);

            color3 rgb = project_color_vector(c);
            image << rgb[0] << " " << rgb[1] << " " << rgb[2] << "\n";
        }
    }


    image.close();
}
