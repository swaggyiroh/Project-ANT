#!/bin/bash
g++ Main.cpp CameraController.cpp -o Main -I/usr/include/opencv4 -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio\
