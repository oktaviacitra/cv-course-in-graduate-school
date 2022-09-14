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
    // Create a new matrix to hold the gray image
    Mat gray(image.size(), CV_8UC1);
    int r, g, b;
    if (!image.data)
    {
        cout << "Could not open or find the image" << endl;
        return -1;
    }
    
    // convert RGB image to gray
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            b = image.at<Vec3b>(i, j)[0];
            g = image.at<Vec3b>(i, j)[1];
            r = image.at<Vec3b>(i, j)[2];
            gray.at<uchar>(i, j) = b * 0.114 + g * 0.587 + r * 0.299;
        }
    }
    
    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", image);
    namedWindow("Result window", WINDOW_AUTOSIZE);
    imshow("Result window", gray);
    waitKey(0);
    return 0;
}
