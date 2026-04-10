cmake_minimum_required(VERSION 3.21)
project(frame-counter VERSION 1.0.0)

find_package(Geode REQUIRED)

geode_configure_project()

add_geode_mod(${PROJECT_NAME}
    SOURCES
        src/main.cpp
)
