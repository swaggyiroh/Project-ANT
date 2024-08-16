#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

class ImageProcessing {
public:
    ImageProcessing(); // Constructor
    ~ImageProcessing(); // Destructor

    // Function to process captured image
    std::string processCapturedImage(const std::string& filename);

private:
    // Private member variables or methods can be added if needed
};

#endif // IMAGE_PROCESSING_H
