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
    GaussianBlur(img, out_blur, Size(3, 3), 0, 0);
    imshow("ORIGINAL", img);
    imshow("BLURRING", out_blur);
    imwrite("blurred-4.jpg", out_blur);
    waitKey(0);
}
