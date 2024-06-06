// Code only to try cropping camera pictures and color recognition

#include "CameraController.h"

#include <opencv2/opencv.hpp>

int CameraController::getLevel() {
    cv::VideoCapture camera(0);

    if(!camera.isOpened()){
        std::cerr << "[ERROR] -> No Camera found!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    camera >> frame; // Capture a frame

    // Crop the image 
    cv::Rect roi(100, 100, 200, 200);
    cv::Mat cropped = frame(roi);

    // Convert to HSV
    cv::Mat hsv;
    cv::cvtColor(cropped, hsv, cv::COLOR_BGR2HSV);

    // Define the color range (e.g., green)
    cv::Scalar lower_green(35, 50, 50);
    cv::Scalar upper_green(85, 255, 255);

    // Create a mask for green pixels
    cv::Mat mask;
    cv::inRange(hsv, lower_green, upper_green, mask);

    // Apply the mask to the cropped image
    cv::Mat result;
    cropped.copyTo(result, mask);

    // Display the result
    cv::imshow("Color Portion", result);
    cv::waitKey(0);

    return 0;

}

