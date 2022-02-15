#include <iostream>

int project(float c) {
    return int(255.99 * c);
}

int main() {

    int NX = 256;
    int NY = 256;

    std::cout << "P3\n" << NX << " " << NY << "\n255\n";

    for (int y = 0; y < NY; y++) {
        for (int x = 0; x < NX; x++) {
            float r = float(x) / float(NX);
            float g = float(y) / float(NY);
            float b = 0.2;

            int R = project(r);
            int G = project(g);
            int B = project(b);

            std::cout << R << " " << G << " " << B << "\n";
        }
    }

    return 0;
}