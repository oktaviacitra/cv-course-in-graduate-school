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
    Mat img, grayImg, edge;
    img = imread("sample.jpg", 1);
    cvtColor(img, grayImg, COLOR_BGR2GRAY);
    //Sobel edge detection dengan custom kernel
    Mat kern1 = (Mat_<float>(3,3)<<1.,2.,1.,0.,0.,0.,-1.,-2.,-1.); // horizontal kernel
    Mat kern2 = (Mat_<float>(3,3)<<-1.,0.,1.,-2.,0.,2.,-1.,0.,1.); // vertical kernel
    Mat res;
    filter2D(grayImg,res,grayImg.type(),kern2);
    filter2D(res,res,res.type(),kern1);
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", grayImg);
    namedWindow("Sobel Filter", WINDOW_AUTOSIZE);
    imshow("Sobel Filter",res);
    waitKey(0);
}
