cmake_minimum_required(VERSION 3.10)
project(rt)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_STANDARD 14)

add_executable(rt main.cpp vec3.h ray.h object.h sphere.h hittable_list.cpp hittable_list.h random.h random.h Camera.h material.h plane.h)