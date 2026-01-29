cmake_minimum_required(VERSION 4.1)
project(8inf259_tp1)

set(CMAKE_CXX_STANDARD 20)

add_executable(8inf259_tp1 main.cpp
        src/Vehicule.cpp
        include/Vehicule.h
        include/TrafficLightState.h
        include/IntersectionType.h
        src/Queue.cpp
        include/Queue.h
        include/Visitor.h
        src/Road.cpp
        include/Road.h
        src/Intersection.cpp
        include/Intersection.h
)
