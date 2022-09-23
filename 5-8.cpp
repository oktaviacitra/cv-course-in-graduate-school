#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
    Mat img, res, kernel;
    float alpha = 0.8;
    float beta = 0.2;
    img = imread("blurred.jpg", 1);
    kernel = Mat::ones(3, 3, CV_32F) / 9;
    filter2D(img, res, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            for (int k = 0; k < 3; k++) {
                res.at<Vec3b>(i, j).val[k] =
                (alpha*img.at<Vec3b>(i, j).val[k]) +
                
                (beta * res.at<Vec3b>(i, j).val[k]);
                
            }
        }
    }
    imshow("Original Image", img);
    imshow("Manual Sharpening", res);
    waitKey(0);
}
