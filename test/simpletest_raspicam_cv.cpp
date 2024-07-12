#include <iostream>
#include <raspicam/raspicam_cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main ( int argc, char **argv ) {
    raspicam::RaspiCam_Cv Camera;
    Mat image;
    int nCount = 100;
    
    // Open camera
    cout << "Opening Camera..." << endl;
    if (!Camera.open()) {
        cerr << "Error opening the camera" << endl;
        return -1;
    }
    
    // Set camera properties
    Camera.set(CAP_PROP_FORMAT, CV_8UC1);  // Set pixel format to grayscale (8-bit)
    
    // Start capture
    cout << "Capturing " << nCount << " frames ...." << endl;
    for (int i = 0; i < nCount; i++) {
        Camera.grab();
        Camera.retrieve(image);
        if (i % 5 == 0)
            cout << "\r captured " << i << " images" << flush;
    }
    cout << "\nStop camera..." << endl;
    Camera.release();
    
    // Save image
    imwrite("raspicam_cv_image.jpg", image);
    cout << "Image saved at raspicam_cv_image.jpg" << endl;
    
    return 0;
}

