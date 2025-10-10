#include <iostream>

using namespace std;

#include "../core/util.h"
#include "../bitmap/bitmap_image.hpp"

void generate_test_ppm() {
    std::string out_path("./artifacts/chapter2.bmp");

    int NX = 256;
    int NY = 256;

    bitmap_image image(NX, NY);

    for (int y = 0; y < NY; y++) {
        for (int x = 0; x < NX; x++) {
            float r = float(x) / float(NX);
            float g = float(y) / float(NY);
            float b = 0.2;

            int R = project_color(r);
            int G = project_color(g);
            int B = project_color(b);

            image.set_pixel(x, y, R, G, B);
        }
    }

    image.save_image(out_path);
}