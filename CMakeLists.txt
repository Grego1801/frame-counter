cmake_minimum_required(VERSION 3.21)
project(frame-counter VERSION 1.0.0)

# If GEODE_SDK is set in the environment, tell CMake where to find Geode
if(DEFINED ENV{GEODE_SDK})
    set(Geode_DIR "$ENV{GEODE_SDK}/lib/cmake/Geode")
endif()

find_package(Geode REQUIRED)

geode_configure_project()

add_geode_mod(${PROJECT_NAME})
