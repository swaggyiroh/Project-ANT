cmake_minimum_required(VERSION 3.28)
project(Project_ANT)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/include/opencv4)

add_executable(Project_ANT
        CameraController.cpp
        CameraController.h
        Main.cpp)
