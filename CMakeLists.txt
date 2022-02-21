cmake_minimum_required(VERSION 3.21)
project(raycaster_in_het_weekend)

set(CMAKE_CXX_STANDARD 14)

################## Conan bootstrap ###############
# see https://blog.conan.io/2018/06/11/Transparent-CMake-Integration.html
# auto-run conan https://github.com/conan-io/cmake-conan
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
"${CMAKE_BINARY_DIR}/conan.cmake"
TLS_VERIFY ON)
endif ()


include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_check(VERSION 1.40.0 REQUIRED)
conan_cmake_autodetect(settings)
#list(APPEND settings cppstd=20)

#conan_add_remote(NAME bincrafters INDEX 1
#        URL https://bincrafters.jfrog.io/artifactory/api/conan/public-conan)
#message(STATUS ${settings})

# Make configuration file from template before conan so it could see local libs
include_directories(${PROPRIETARY_COMMON})
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

#get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
#message(STATUS "INCLUDE_DIRECTORIES ${dirs}")
set(CONAN_REBUILD missing)

conan_cmake_run(CONANFILE "./conanfile.txt"
BUILD_TYPE ${CMAKE_BUILD_TYPE}
BASIC_SETUP
BUILD missing ${CONAN_REBUILD}
SETTINGS ${settings}
)

##############################  END COANAN bottstrap

find_package(glm REQUIRED)
find_package(spdlog REQUIRED)

set(EXE raycaster_in_het_weekend)

add_executable(${EXE}
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
        chapters/6_antialiasing.cpp
        chapters/6_antialiasing.h
        camera.cpp camera.h)

target_link_libraries(${EXE} glm::glm spdlog::spdlog)

#add_subdirectory(glm)
#target_include_directories(raycaster_in_het_weekend glm)

#find_package(glm REQUIRED)
#target_link_libraries(raycaster_in_het_weekend glm::glm)

