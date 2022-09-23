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
    Mat img, out_sharp;
    /// Load image
    img = imread("blurred.jpg", 1);
    GaussianBlur(img, out_sharp, Size(5, 5), 0, 0);
    addWeighted(img, 1.5, out_sharp, -0.5, 0, out_sharp);
    imshow("ORIGINAL", img);
    imshow("SHARP", out_sharp);
    waitKey(0);
}
