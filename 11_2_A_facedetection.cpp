#include <iostream>
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
    // Default resolution of the frame is obtained.The default resolution is system dependent.
    int frame_width = capture.get(CAP_PROP_FRAME_WIDTH);
    int frame_height = capture.get(CAP_PROP_FRAME_HEIGHT);
    // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
    VideoWriter video("video_citra.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height));
    while(1)
    {
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
        // Write the frame into the file 'outcpp.avi'
        video.write(image);
        imshow("Detected Face", image);
        char c = (char)waitKey(1);
        if (c == 27)
            break;
        
    }
    // When everything done, release the video capture and write object
    capture.release();
    video.release();
    // Closes all the windows
    destroyAllWindows();
    return 0;
}
