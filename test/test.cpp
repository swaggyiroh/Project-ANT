// Opencv needs to be installed on your Raspberry Pi
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    VideoCapture cap(0); // if you only have 1 camera connected.
    if (!cap.isOpened()) {
        cout << "Cannot open camera\n";
        return -1;
    }

    Mat frame;
    while (true) {
        bool ret = cap.read(frame); // or cap >> frame;
        if (!ret) {
            cout << "Error. Fail to receive frame.\n";
            break;
        }
        ......
        // process frame
        ......
        if (waitKey(1) == 'q') {
            break;
        }
    }

    return 0;
}
