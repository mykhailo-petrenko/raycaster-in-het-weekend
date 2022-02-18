#include <iostream>
#include <fstream>

using namespace std;

#include "../util.h"

void generate_test_ppm() {
    ofstream test_ppm;
    test_ppm.open("./artifacts/test.ppm");

    int NX = 256;
    int NY = 256;

    test_ppm << "P3\n" << NX << " " << NY << "\n255\n";

    for (int y = 0; y < NY; y++) {
        for (int x = 0; x < NX; x++) {
            float r = float(x) / float(NX);
            float g = float(y) / float(NY);
            float b = 0.2;

            int R = project_color(r);
            int G = project_color(g);
            int B = project_color(b);

            test_ppm << R << " " << G << " " << B << "\n";
        }
    }

    test_ppm.close();
}