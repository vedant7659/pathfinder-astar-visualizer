cmake_minimum_required(VERSION 3.10)

project(PathFinder)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(
    PathFinder
    src/main.cpp
    src/astar.cpp
)

target_link_libraries(
    PathFinder
    sfml-graphics
    sfml-window
    sfml-system
)