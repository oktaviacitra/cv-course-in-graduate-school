#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image;
    image = imread("kids.jpg");
    namedWindow("window1", 1);
    imshow("window1", image);
    CascadeClassifier face_cascade;
    face_cascade.load("haarcascade_frontalface_alt.xml");
    if (face_cascade.empty()) {
        cerr << "Load XML Error" << endl;
        return 0;
    }
    std::vector<Rect> faces;
    face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
    for (int i = 0; i < faces.size(); i++) {
        Point center(faces[i].x + faces[i].width * 0.5, faces[i].y + faces[i].height * 0.5);
        ellipse(image, center, Size(faces[i].width * 0.5, faces[i].height * 0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
    }
    imshow("Detected Face", image);
    waitKey(0);
    return 0;
}
