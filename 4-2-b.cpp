#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("sample.jpg", IMREAD_COLOR);
    if (!image.data)
    {
        cout << "Could not open or find the image" << endl;
        return -1;
    }
    
    Mat gray, xyz, ycrcb, hsv, lab;
    // convert RGB image
    cvtColor(image, gray, COLOR_BGR2GRAY);
    cvtColor(image, xyz, COLOR_BGR2XYZ);
    cvtColor(image, ycrcb, COLOR_BGR2YCrCb);
    cvtColor(image, hsv, COLOR_BGR2HSV);
    cvtColor(image, lab , COLOR_BGR2Lab);
    imshow("Display window", image);
    imshow("Result Gray", gray);
    imshow("Result RGB XYZ", xyz);
    imshow("Result RGB YcRCb", ycrcb);
    imshow("Result RGB HSV", hsv);
    imshow("Result RGB Lab", lab);
    waitKey(0);
    return 0;
}
