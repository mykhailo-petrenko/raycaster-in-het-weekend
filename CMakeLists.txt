cmake_minimum_required(VERSION 3.24)
project(raycaster_in_het_weekend)

set(CMAKE_CXX_STANDARD 17)

find_package(glm REQUIRED)
find_package(spdlog REQUIRED)


add_executable(chapter-2-generate-ppm
        chapter-2-generate-ppm.cpp
        core/geometry.hpp
        core/util.cpp
        core/util.h
        core/hittable.hpp
        chapters/2_generate-ppm.cpp
        chapters/2_generate-ppm.h
        core/camera.cpp
        core/camera.h
        core/logger.hpp
)
target_link_libraries(chapter-2-generate-ppm glm::glm spdlog::spdlog)

add_executable(chapter-3-ray-and-background
        chapter-3-ray-and-background.cpp
        core/geometry.hpp
        core/util.cpp
        core/util.h
        core/hittable.hpp
        chapters/3_ray_and_background.cpp
        chapters/3_ray_and_background.h
        core/camera.cpp
        core/camera.h
        core/logger.hpp
)
target_link_libraries(chapter-3-ray-and-background glm::glm spdlog::spdlog)

add_executable(chapter-4-ray-and-sphere
        chapter-4-ray-and-sphere.cpp
        core/geometry.hpp
        core/util.cpp
        core/util.h
        core/hittable.hpp
        chapters/4_ray_and_sphere.cpp
        chapters/4_ray_and_sphere.h
        core/camera.cpp
        core/camera.h
        core/logger.hpp
)
target_link_libraries(chapter-4-ray-and-sphere glm::glm spdlog::spdlog)

add_executable(chapter-5-surface-normals
        chapter-5-surface-normals.cpp
        core/geometry.hpp
        core/util.cpp
        core/util.h
        core/hittable.hpp
        chapters/5_surface_normals.cpp
        chapters/5_surface_normals.h
        core/camera.cpp
        core/camera.h
        core/logger.hpp
)
target_link_libraries(chapter-5-surface-normals glm::glm spdlog::spdlog)

add_executable(chapter-6-antialiasing
        chapter-6-antialiasing.cpp
        core/geometry.hpp
        core/util.cpp
        core/util.h
        core/hittable.hpp
        chapters/6_antialiasing.cpp
        chapters/6_antialiasing.h
        core/camera.cpp
        core/camera.h
        core/logger.hpp
)
target_link_libraries(chapter-6-antialiasing glm::glm spdlog::spdlog)

add_executable(chapter-7-diffuse-materials
        chapter-7-diffuse-materials.cpp
        core/geometry.hpp
        core/util.cpp
        core/util.h
        core/hittable.hpp
        chapters/7_diffuse_materials.cpp
        chapters/7_diffuse_materials.h
        core/camera.cpp
        core/camera.h
        core/logger.hpp
)
target_link_libraries(chapter-7-diffuse-materials glm::glm spdlog::spdlog)

add_executable(chapter-8-metal-materials
        chapter-8-metal-materials.cpp
        core/geometry.hpp
        core/util.cpp
        core/util.h
        core/hittable.hpp
        core/camera.cpp
        core/camera.h
        core/logger.hpp
)
target_link_libraries(chapter-8-metal-materials glm::glm spdlog::spdlog)

