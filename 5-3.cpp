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
    const double PI = 4.0*atan(1.0);
    double sigma = 2;
    const int kernalWidth = 3;
    const int kernalHeight = 3;
    float kernalArray[kernalWidth][kernalHeight];
    double total = 0;
    
    //calculate each relavant value to neighour pixels and store it in 2d array
    for (int row = 0; row < kernalWidth; row++) {
        for (int col = 0; col < kernalHeight; col++) {
            float value = float(1 / (2 * PI*pow(sigma, 2)))*exp(-(pow(row - kernalWidth / 2, 2) + pow(col - kernalHeight / 2, 2)) / (2 * pow(sigma, 2)));
            kernalArray[row][col] = value;
            total += value;
        }
    }
    //Scale value in 2d array in to 1
    for (int row = 0; row < kernalWidth; row++) {
        for (int col = 0; col < kernalHeight; col++) {
            kernalArray[row][col] = float(kernalArray[row][col] / total);
        }
    }
    /*End producing Gaussian filter kernel*/
    
    Mat RGBImage;
    RGBImage = imread("sample.jpg");
    Mat grayScaleImage(RGBImage.size(), CV_8UC1);
    Mat FinalImage(RGBImage.size(), CV_8UC1);
    cvtColor(RGBImage, grayScaleImage, COLOR_BGR2GRAY);
    int rows = grayScaleImage.rows;
    int cols = grayScaleImage.cols;
    int verticleImageBound = (kernalHeight - 1) / 2;
    int horizontalImageBound = (kernalWidth - 1) / 2;
    for (int row = 0 + verticleImageBound; row < rows - verticleImageBound; row++) {
        for (int col = 0 + horizontalImageBound; col < cols - horizontalImageBound; col++) {
            float value = 0.0;
            for (int kRow = 0; kRow < kernalHeight; kRow++) {
                for (int kCol = 0; kCol < kernalWidth; kCol++) {
                    //multiply pixel value with corresponding gaussian kernal value
                    float pixel = grayScaleImage.at<uchar>(kRow + row - verticleImageBound, kCol + col - horizontalImageBound)*kernalArray[kRow][kCol];
                    value += pixel;
                }
            }
            //assign new values to central point
            FinalImage.at<uchar>(row, col) = cvRound(value);
        }
    }
    namedWindow("Original Image", 1);
    imshow("Original Image", grayScaleImage);
    namedWindow("Filtered Image", 1);
    imshow("Filtered Image", FinalImage);
    waitKey();
    return 0;
}
