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

    Scalar red_lower1(0, 0, 100); //Scalar is BGR = BLUE ; RED ; GREEN
    Scalar red_upper1(90, 90, 255);

    Scalar green_lower1(0, 100, 0);
    Scalar green_upper1(90, 255, 90);

    Scalar green_lower2(0, 180, 0);
    Scalar green_upper2(160, 255, 120);

    Scalar green_lower3(0, 40, 0);
    Scalar green_upper3(20, 100, 20);
    
    Scalar blue_lower1(100, 0, 0);
    Scalar blue_upper1(255, 90, 90);

    Scalar blue_lower2(180, 100, 0);
    Scalar blue_upper2(255, 160, 70);
    
    // Create masks for each color in RGB
    Mat red_mask, green_mask1, green_mask2, green_mask3, blue_mask1, blue_mask2;
    inRange(image, red_lower1, red_upper1, red_mask);
    inRange(image, green_lower1, green_upper1, green_mask1);
    inRange(image, green_lower2, green_upper2, green_mask2);
    inRange(image, green_lower3, green_upper3, green_mask3);
    inRange(image, blue_lower1, blue_upper1, blue_mask1);
    inRange(image, blue_lower2, blue_upper2, blue_mask2);

    // Combine masks if there are multiple ranges
    Mat green_mask = green_mask1 | green_mask2 | green_mask3;
    Mat blue_mask = blue_mask1 | blue_mask2;
    
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

    // Further processing based on RGB percentages
    if (greenPercentage > 1 || bluePercentage > 1 || redPercentage > 1) {
        if (greenPercentage > bluePercentage && greenPercentage > redPercentage) {
        fuellmenge = "70% - 100%";
        } else if (bluePercentage > greenPercentage && bluePercentage > redPercentage) {
        fuellmenge = "40% - 70%";
        } else if (redPercentage > greenPercentage && redPercentage > bluePercentage) {
        fuellmenge = "10% - 40%";
        }
    }

    return fuellmenge;
}
