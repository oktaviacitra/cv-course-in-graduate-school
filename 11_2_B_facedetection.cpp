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
    int hitung = 0;
    int frame_width = capture.get(CAP_PROP_FRAME_WIDTH);
    int frame_height = capture.get(CAP_PROP_FRAME_HEIGHT);
    // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
    VideoWriter video("Video citra 2.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height));
    while (1)
    {
        hitung++;
        Mat image;
        capture >> image;
        if (image.empty())
        {
            break;
        }
        //cvtColor(image, gray, COLOR_RGB2GRAY);
        int64 start = getTickCount();
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
        double fps = getTickFrequency() / (cv::getTickCount() - start);
        printf("%d. Frame rate per second = %f\n", hitung, fps);
        putText(image, "FPS : " + to_string(fps), cv::Point(10, 30), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 255, 255), 2);
        
        video.write(image);
        imshow("Detected Face", image);
        char c = (char)waitKey(1);
        if (c == 27)
            break;
        
    }
    capture.release();
    video.release();
    destroyAllWindows();
    return 0;
}
