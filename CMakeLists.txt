cmake_minimum_required(VERSION 3.24)
project(raycaster_in_het_weekend)

set(CMAKE_CXX_STANDARD 17)

find_package(glm REQUIRED)
find_package(spdlog REQUIRED)

add_executable(${PROJECT_NAME}
        main.cpp
        geometry.hpp
        util.cpp
        util.h
        hittable.hpp
#        chapters/2_generate-ppm.cpp
#        chapters/2_generate-ppm.h
#        chapters/3_ray_and_background.cpp
#        chapters/3_ray_and_background.h
#        chapters/4_ray_and_sphere.cpp
#        chapters/4_ray_and_sphere.h
#        chapters/5_surface_normals.cpp
#        chapters/5_surface_normals.h
#        chapters/6_antialiasing.cpp
#        chapters/6_antialiasing.h
        chapters/7_diffuse_materials.cpp
        chapters/7_diffuse_materials.h
        camera.cpp
        camera.h
        )

target_link_libraries(${PROJECT_NAME} glm::glm spdlog::spdlog)

