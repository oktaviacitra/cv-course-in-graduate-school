#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

static Scalar randomColor(RNG& rng) {
    int icolor = (unsigned)rng;
    return Scalar(icolor & 255, (icolor >> 8) & 255, (icolor >> 16) & 255);
}

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Error opening video streamor file" << endl;
        return -1;
    }
    
    int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
    const int DELAY = 5;
    int lineType = LINE_AA;
    RNG rng(0xFFFFFFFF);
    int x1 = -frame_width / 2, x2 = frame_width * 3 / 2, y1 = -frame_height / 2, y2 = frame_height * 3 / 2;
    VideoWriter video("video3-4.avi", VideoWriter::fourcc('m', 'p', '4', 'v'), 10, Size(frame_width, frame_height));
    
    while (1) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) break;
        
        Point center;
        center.x = rng.uniform(1, 3);
        center.y = rng.uniform(1, 3);
        circle(frame, center, rng.uniform(0, 300), randomColor(rng), rng.uniform(-1, 9), lineType);

        Point pt1, pt2;
        pt1.x = rng.uniform(x1, x2);
        pt1.y = rng.uniform(y1, y2);
        pt2.x = rng.uniform(x1, x2);
        pt2.y = rng.uniform(y1, y2);
        int arrowed = rng.uniform(0, 6);
        line(frame, pt1, pt2, randomColor(rng), rng.uniform(1, 10), lineType);
        
        Size textsize = getTextSize("Praktikum 3", QT_FONT_NORMAL, 3, 5, 0);
        Size textsize2 = getTextSize("Oktavia Citra", FONT_HERSHEY_SCRIPT_SIMPLEX, 1, 1, 0);
        
        Point org((frame_width - textsize.width) / 2, (frame_height - textsize.height) / 2);
        Point org1((frame_width - textsize2.width), (frame_height - textsize2.height));
        
        putText(frame, "Praktikum 3", org, QT_FONT_NORMAL, 1, Scalar(77, 56, 0), 3, lineType);
        putText(frame, "Oktavia Citra", org1, FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(240, 230, 255), 2, lineType);
        video.write(frame);
        imshow("Frame", frame);
        char c = (char)waitKey(1);
        if (c == 27) break;
    }
    cap.release();
    video.release();
    destroyAllWindows();
    return 0;
}
