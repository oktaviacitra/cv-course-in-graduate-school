#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Error opening video streamor file" << endl;
        return -1;
    }
    
    while (1) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) break;
        imshow("Frame", frame);
        char c = (char)waitKey(25);
        if (c == 27) break;
    }
    
    cap.release();
    destroyAllWindows();
    return 0;
}
