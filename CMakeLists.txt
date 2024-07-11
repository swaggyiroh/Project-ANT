cmake_minimum_required(VERSION 3.28)
project(Project_ANT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the current directory
include_directories(.)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Add the executable
add_executable(Project_ANT
        CameraController.cpp
        Main.cpp
)

# Link OpenCV libraries
target_link_libraries(Project_ANT ${OpenCV_LIBS})
