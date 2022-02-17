cmake_minimum_required(VERSION 3.21)
project(raycaster_in_het_weekend)

set(CMAKE_CXX_STANDARD 14)

add_executable(raycaster_in_het_weekend
        generate-ppm.cpp
        generate-ppm.h
        main.cpp)

add_subdirectory(glm)
target_link_libraries(raycaster_in_het_weekend glm::glm)
#target_include_directories(raycaster_in_het_weekend glm)

#find_package(glm REQUIRED)
#target_link_libraries(raycaster_in_het_weekend glm::glm)