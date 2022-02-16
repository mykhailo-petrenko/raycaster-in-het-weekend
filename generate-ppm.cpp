#include <iostream>
#include <fstream>

using namespace std;

int project(float c) {
    return int(255.99 * c);
}

void generate_test_ppm() {
    ofstream test_ppm;
    test_ppm.open("./test.ppm");

    int NX = 256;
    int NY = 256;

    test_ppm << "P3\n" << NX << " " << NY << "\n255\n";

    for (int y = 0; y < NY; y++) {
        for (int x = 0; x < NX; x++) {
            float r = float(x) / float(NX);
            float g = float(y) / float(NY);
            float b = 0.2;

            int R = project(r);
            int G = project(g);
            int B = project(b);

            test_ppm << R << " " << G << " " << B << "\n";
        }
    }

    test_ppm.close();
}