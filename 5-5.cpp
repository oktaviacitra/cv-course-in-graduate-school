#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
    Mat img, out_blur;
    /// Load image
    img = imread("sample.jpg", 1);
    medianBlur(img, out_blur, 3);
    imshow("ORIGINAL", img);
    imshow("BLURRING", out_blur);
    imwrite("blurred.jpg", out_blur);
    waitKey(0);
}
