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
    const char* source_window = "Source image";
    const char* equalized_window = "Manual Equalized";
    Mat image, gray_image;
    image = imread("sample.jpg", IMREAD_COLOR);
    cvtColor(image, gray_image, COLOR_BGR2GRAY);
    const int histSize = 256;
    int hist[histSize];
    for (int i = 0; i < 256; i++) {
        hist[i] = 0;
    }
    // menghitung per-pixel
    for (int y = 0; y < gray_image.rows; y++) {
        for (int x = 0; x < gray_image.cols; x++) {
            hist[(int)gray_image.at<uchar>(y, x)]++;
        }
    }
    //menghitung ukuran image
    int size = gray_image.rows * gray_image.cols;
    float alpha = 255.0 / size;
    // menghitung probabilitas setiap pixel
    float prob[256];
    for (int i = 0; i < 256; i++) {
        prob[i] = (double)hist[i]/size;
    }
    //menghitung histogram kumulatif
    int cumhistogram[256];
    cumhistogram[0] = hist[0];
    for (int i = 1; i < 256; i++){
        cumhistogram[i] = hist[i] + cumhistogram[i-1];
    }
    // Scale histogram
    int sk[256];
    for (int i = 0; i < 256; i++) {
        sk[i] = cvRound((double)cumhistogram[i] * alpha);
    }
    // Generate histogram equalization
    float histEq[256];
    for (int i = 0; i < 256; i++){
        histEq[i] = 0;
    }
    for (int i = 0; i < 256; i++){
        histEq[sk[i]] += prob[i];
    }
    int res[256];
    for (int i = 0; i < 256; i++) {
        res[i] = cvRound(histEq[i] * 255);
    }
    // Generate the equlized image
    Mat equalizedImage = gray_image.clone();
    for (int y = 0; y < gray_image.rows; y++) {
        for (int x = 0; x < gray_image.cols; x++) {
            equalizedImage.at<uchar>(y, x) = saturate_cast<uchar>(sk[gray_image.at<uchar>(y, x)]);
        }
    }
    namedWindow(source_window, WINDOW_AUTOSIZE);
    namedWindow(equalized_window, WINDOW_AUTOSIZE);
    imshow(source_window, gray_image);
    imshow(equalized_window, equalizedImage);
    waitKey(0);
    return 0;
}
