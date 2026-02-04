cmake_minimum_required(VERSION 4.1)
project(8inf259_tp1)

set(CMAKE_CXX_STANDARD 20)

add_executable(8inf259_tp1 main.cpp
        src/Queue.cpp
        include/Queue.h
        include/Visitors/Visitor.h
        include/Intersections/Intersection.h
        include/Intersections/FourStopIntersection.h
        include/Road.h
        include/Vehicle.h
        include/Visitors/HighestWaitVisitor.h
        src/Road.cpp
        src/Vehicle.cpp
        src/Intersections/FourStopIntersection.cpp
        src/Visitors/HighestWaitVisitor.cpp
        include/Intersections/FixedCycleIntersection.h
        src/Intersections/FixedCycleIntersection.cpp
        include/Direction.h
        src/Direction.cpp
        src/Intersections/PriorityIntersection.cpp
        include/Intersections/PriorityIntersection.h
        src/TrafficSystem.cpp
        include/TrafficSystem.h
        src/Visitors/IncreaseWaitVisitor.cpp
        include/Visitors/IncreaseWaitVisitor.h
        src/Visitors/DisplayVehicleVisitor.cpp
        include/Visitors/DisplayVehicleVisitor.h
        include/Visitors/Client.h
)
