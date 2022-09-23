#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace cv;
using namespace std;

int main()
{
    Mat img;
    Mat edge;
    img = imread("sample.jpg", 1);
    Sobel(img, edge, -1, 1, 1, 3, 1.0, 0.0, 4);
    //Sobel(img, edge, -1, 2, 2, 5, 1.0, 0.0, 4);
    //Sobel(img, edge, -1, 3, 3, 7, 1.0, 0.0, 4);
    //Sobel(img, edge, -1, 5, 5, 11, 1.0, 0.0, 4);
    imshow("ORIGINAL", img);
    imshow("EDGE", edge);
    waitKey(0);
}
