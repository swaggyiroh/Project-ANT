#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <opencv2/opencv.hpp>
#include <iostream>

class ImageProcessing {
public:
    ImageProcessing(); // Constructor
    ~ImageProcessing(); // Destructor

    // Function to process captured image
    string processCapturedImage(const std::string& filename);

private:
    // Private member variables or methods can be added if needed
};

#endif // IMAGE_PROCESSING_H
