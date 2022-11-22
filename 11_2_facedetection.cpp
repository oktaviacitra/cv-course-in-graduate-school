#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture capture(0);
    if (!capture.isOpened())
    {
        cout << "Error" << endl;
    }
    
    for (;;){
        double t1 = (double)getTickCount();
        Mat image;
        capture >> image;
        if (image.empty())
        {
            break;
        }
        
        CascadeClassifier face_cascade;
        face_cascade.load("haarcascade_frontalface_alt.xml");
        if (face_cascade.empty()) {
            cerr << "Load XML Error" << endl;
            return 0;
        }
        
        vector<Rect> faces;
        face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(24, 24));
        for (int i = 0; i < faces.size(); i++) {
            Point center(faces[i].x + faces[i].width * 0.5, faces[i].y + faces[i].height * 0.5);
            
            ellipse(image, center, Size(faces[i].width * 0.5, faces[i].height * 0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
            
        }
        imshow("Detected Face", image);
        waitKey(1);
    }
    // Closes all the windows
    destroyAllWindows();
    return 0;
}
