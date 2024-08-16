#include "ImageProcessing.h"
#include <string>

using namespace cv;
using namespace std;

ImageProcessing::ImageProcessing() {
    // Constructor implementation if needed
}

ImageProcessing::~ImageProcessing() {
    // Destructor implementation if needed
}

std::string ImageProcessing::processCapturedImage(const std::string& filename) {
    Mat image = imread(filename);

    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Define the range of each color in RGB
    Scalar red_lower(255, 0, 0);
    Scalar red_upper(255, 100, 100);

    Scalar green_lower(153, 255, 0);
    Scalar green_upper(0, 255, 145);

    Scalar blue_lower(0, 166, 255);
    Scalar blue_upper(38, 0, 255);

    // Create masks for each color in RGB
    Mat red_mask, green_mask, blue_mask;
    inRange(image, red_lower, red_upper, red_mask);
    inRange(image, green_lower, green_upper, green_mask);
    inRange(image, blue_lower, blue_upper, blue_mask);

    // Count the number of non-zero pixels in each mask
    int totalPixels = image.rows * image.cols;
    int redPixels = countNonZero(red_mask);
    int greenPixels = countNonZero(green_mask);
    int bluePixels = countNonZero(blue_mask);

    // Calculate percentages
    double redPercentage = (double)redPixels / totalPixels * 100.0;
    double greenPercentage = (double)greenPixels / totalPixels * 100.0;
    double bluePercentage = (double)bluePixels / totalPixels * 100.0;

    // Print the percentages
    cout << "Red Percentage: " << redPercentage << "%" << endl;
    cout << "Green Percentage: " << greenPercentage << "%" << endl;
    cout << "Blue Percentage: " << bluePercentage << "%" << endl;

    string fuellmenge = "";

    // TODO: Further processing based on RGB percentages
    if (greenPercentage > 10.0) {
    fuellmenge = "voll";
    } else if (bluePercentage > 10.0) {
    fuellmenge = "mittel";
    } else if (redPercentage > 10.0) {
    fuellmenge = "fast leer";
    }
    
    return fuellmenge;
}
