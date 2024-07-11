#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Open the camera with the Video4Linux2 backend
    cv::VideoCapture camera(0, cv::CAP_V4L2);

    if (!camera.isOpened()) {
        std::cerr << "[ERROR] -> No Camera found with V4L2 backend!" << std::endl;
        return -1;
    }

    // Set the camera resolution to a lower value to save memory
    camera.set(cv::CAP_PROP_FRAME_WIDTH, 320);
    camera.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
    camera.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

    cv::Mat frame;
    if (!camera.read(frame)) { // Capture a frame and check if successful
        std::cerr << "[ERROR] -> Failed to capture frame!" << std::endl;
        return -1;
    }

    // Check if the frame is empty
    if (frame.empty()) {
        std::cerr << "[ERROR] -> Captured frame is empty!" << std::endl;
        return -1;
    }

    // Print frame dimensions
    std::cout << "Captured frame dimensions: " << frame.cols << "x" << frame.rows << std::endl;

    // Release the camera
    camera.release();

    return 0;
}
