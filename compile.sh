#!/bin/bash

## compile main only with CameraController.

#g++ Main.cpp CameraController.cpp -o Main -I/usr/include/opencv4 -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio\

g++ -o process_image process_image.cpp -I/usr/include/opencv4

## compile main with CameraControler and dht sensor.

## g++ Main.cpp CameraController.cpp DHT22.cpp -o Main -I/usr/include/opencv4 -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lwiringPi