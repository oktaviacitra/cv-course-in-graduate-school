#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int g_slider_position = 0;

void onTrackbarSlide(int pos) {
    setTrackbarPos("Position", "AVI", pos);
}

int main() {
    int noFrame;
    namedWindow("AVI", 1);
    
    // Create a VideoCapture object and open the input file
    // If the input is the web camera, pass 0 instead of the video file name
    VideoCapture cap("/Users/oktaviacitra/comvis/2/video.avi");
    // Check if camera opened successfully
    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }
    
    int totalframes = (int)cap.get(CAP_PROP_FRAME_COUNT);
    if (totalframes != 0) {
        createTrackbar("Position", "AVI", &g_slider_position, totalframes);
    }
    
    while (1) {
        Mat frame;
        noFrame = cap.get(CAP_PROP_POS_FRAMES);
        onTrackbarSlide(noFrame);
        //cout << noFrame << endl;
        cap >> frame;
        // If the frame is empty, break immediately
        if (frame.empty()) break;
        // Display the resulting frame
        imshow("AVI", frame);
        // Press ESC on keyboard to exit
        char c = (char)waitKey(25);
        if (c == 27) break;
    }
    
    // When everything done, release the video capture object
    cap.release();
    
    // Closes all the frames
    destroyAllWindows();
    return(0);
}
