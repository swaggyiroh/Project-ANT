#include "CameraController.h"
#include <opencv2/opencv.hpp>
#include <iostream>

int CameraController::getlevel() {
    // Try to open the camera with the default backend
    cv::VideoCapture camera(0);

    if (!camera.isOpened()) {
        std::cerr << "[ERROR] -> No Camera found with default backend!" << std::endl;

        // Try opening the camera with a different backend, e.g., V4L2 (Video4Linux2)
        camera.open(0, cv::CAP_V4L2);
        if (!camera.isOpened()) {
            std::cerr << "[ERROR] -> No Camera found with V4L2 backend either!" << std::endl;
            return -1;
        }
    }

    cv::Mat frame;
    camera.read(frame); // Capture a frame

    // Check if the frame is empty
    if (frame.empty()) {
        std::cerr << "[ERROR] -> Captured frame is empty!" << std::endl;
        return -1;
    }

    // Print frame dimensions
    std::cout << "Captured frame dimensions: " << frame.cols << "x" << frame.rows << std::endl;

    // Convert to HSV
    cv::Mat hsv;
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

    // Enhance contrast in the V channel (Histogram Equalization)
    std::vector<cv::Mat> channels;
    cv::split(hsv, channels);
    cv::equalizeHist(channels[2], channels[2]);
    cv::merge(channels, hsv);

    // Define the color ranges for green 
    cv::Scalar lower_green(35, 50, 50);
    cv::Scalar upper_green(85, 255, 255);
    // red 
    cv::Scalar lower_red1(0, 50, 50);
    cv::Scalar upper_red1(10, 255, 255);
    cv::Scalar lower_red2(170, 50, 50);
    cv::Scalar upper_red2(180, 255, 255);
    // and blue
    cv::Scalar lower_blue(100, 50, 50);
    cv::Scalar upper_blue(130, 255, 255);

    // masks for each color
    cv::Mat mask_green, mask_red1, mask_red2, mask_blue;
    cv::inRange(hsv, lower_green, upper_green, mask_green);
    cv::inRange(hsv, lower_red1, upper_red1, mask_red1);
    cv::inRange(hsv, lower_red2, upper_red2, mask_red2);
    cv::inRange(hsv, lower_blue, upper_blue, mask_blue);

    // Combine masks for red 
    cv::Mat mask_red;
    cv::bitwise_or(mask_red1, mask_red2, mask_red);

    // Count pixels for each color
    int total_pixels = frame.cols * frame.rows;
    int green_pixels = cv::countNonZero(mask_green);
    int red_pixels = cv::countNonZero(mask_red);
    int blue_pixels = cv::countNonZero(mask_blue);

    // Calculate percentages
    float green_percentage = (static_cast<float>(green_pixels) / total_pixels) * 100.0;
    float red_percentage = (static_cast<float>(red_pixels) / total_pixels) * 100.0;
    float blue_percentage = (static_cast<float>(blue_pixels) / total_pixels) * 100.0;

    // Print percentages
    std::cout << "Green pixels percentage: " << green_percentage << "%" << std::endl;
    std::cout << "Red pixels percentage: " << red_percentage << "%" << std::endl;
    std::cout << "Blue pixels percentage: " << blue_percentage << "%" << std::endl;



    camera.release();


    return 0;
}
