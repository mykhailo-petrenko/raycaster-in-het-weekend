#include <iostream>
#include <glm/vec3.hpp>

#include "generate_test_ppm.h";

int main() {
    glm::vec3 v = glm::vec3(1., 1., 1.);

    generate_test_ppm();
    return 0;
}
