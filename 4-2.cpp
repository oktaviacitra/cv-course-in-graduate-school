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
    
    // Create a new matrix to hold the gray image
    Mat gray;
    
    // convert RGB image to gray
    cvtColor(image, gray, COLOR_BGR2GRAY);
    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", image);
    namedWindow("Result window", WINDOW_AUTOSIZE);
    imshow("Result window", gray);
    waitKey(0);
    return 0;
}
