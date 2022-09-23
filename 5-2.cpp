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
    Mat image = imread("sample.jpg");
    // Print Error message if image is null
    if (image.empty())
    {
        cout << "Could not read image" << endl;
    }
    Mat kernel2 = Mat::ones(3, 3, CV_64F);
    // Normalize the elements
    kernel2 = kernel2 / 9;
    Mat img;
    filter2D(image, img, -1, kernel2, Point(-1, -1), 0, BORDER_DEFAULT);
    imshow("Original", image);
    imshow("Blur Filter2D", img);
    imwrite("blur_kernel.jpg", img);
    waitKey();
    destroyAllWindows();
}
