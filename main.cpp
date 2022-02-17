#include <iostream>
#include <glm/vec3.hpp>

#include "generate-ppm.h"

int main() {
    glm::vec3 v = glm::vec3(1., 1., 1.);

    std::cout << "Hello";

    generate_test_ppm();
    return 0;
}
