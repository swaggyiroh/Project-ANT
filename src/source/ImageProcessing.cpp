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
        return "";
    }

    Scalar red_lower(0, 0, 100); //Scalar is BGR = BLUE ; RED ; GREEN
    Scalar red_upper(150, 150, 255);

    Scalar green_lower(0, 50, 0);
    Scalar green_upper(180, 255, 200);

    Scalar blue_lower(50, 0, 0);
    Scalar blue_upper(255, 200, 200);
    
    // Create masks for each color in BGR
    Mat red_mask, green_mask, blue_mask;
    inRange(image, red_lower, red_upper, red_mask);
    inRange(image, green_lower, green_upper, green_mask);
    inRange(image, blue_lower, blue_upper, blue_mask);

    // Count the number of non-zero pixels in each mask
    int totalPixels = image.rows * image.cols;
    int redPixels = countNonZero(red_mask);
    int greenPixels = countNonZero(green_mask);
    int bluePixels = countNonZero(blue_mask);

    //param to tune
    //int totalPixels = totalPixels / 10;
    
    // Calculate percentages
    double redPercentage = (double)redPixels / totalPixels * 100.0;
    double greenPercentage = (double)greenPixels / totalPixels * 100.0;
    double bluePercentage = (double)bluePixels / totalPixels * 100.0;

    // Print the percentages
    cout << "Red Percentage: " << redPercentage << "%" << endl;
    cout << "Green Percentage: " << greenPercentage << "%" << endl;
    cout << "Blue Percentage: " << bluePercentage << "%" << endl;

    string fuellmenge = "Kein Futter zu erkennen";

    // TODO: Further processing based on BGR percentages
    if (greenPercentage > 10.0) {
    fuellmenge = "70% - 100%";
    } else if (bluePercentage > 10.0) {
    fuellmenge = "40% - 70%";
    } else if (redPercentage > 10.0) {
    fuellmenge = "10% - 40%";
    }
    
    return fuellmenge;
}
