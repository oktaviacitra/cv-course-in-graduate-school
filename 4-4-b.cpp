#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main()
{
    Mat image, gray_image;
    image = imread("sample.jpg", IMREAD_COLOR);
    cvtColor(image, gray_image, COLOR_BGR2GRAY);
    imshow("Grayscale Image", gray_image);
    int width = gray_image.cols;
    int height = gray_image.rows;
    const int histSize = 256;
    int hist[histSize];
    for (int i = 0; i < histSize; i++) {
        hist[i] = 0;
    }
    int max = 0;
    for (int i = 0; i < gray_image.rows; ++i) {
        for (int j = 0; j < gray_image.cols; ++j) {
            //Vec3b means 'uchar 3ch'
            unsigned char k = gray_image.at<unsigned char>(i, j);
            hist[k] ++;
            if (max < hist[k])
                max = hist[k];
        }
    }
    Mat histogram = Mat::zeros(Size(histSize, max+1), CV_8U);
    int sum = 0;
    for (int i = 0; i < histSize; ++i) {
        sum = sum + hist[i];
        for (int j = 0; j < hist[i]; ++j) {
            histogram.at< unsigned char >(max-j, i) = 255;
        }
    }
    namedWindow("Histogram Manual", 0);
    imshow("Histogram Manual", histogram);
    waitKey(0);
    return 0;
}
