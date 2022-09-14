#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main(int argc, char**argv) {
    Mat image, gray_image;
    image = imread("sample.JPG", IMREAD_COLOR);
    cvtColor(image, gray_image,COLOR_BGR2GRAY);
    imshow("Grayscale Image", gray_image);
    /// bin
    int histSize = 256;
    /// mengatur ranges
    float range[] = { 0, 256 };
    const float* histRange = { range };
    bool uniform =true;
    bool accumulate =false;
    Mat b_hist;
    /// menghitung histogram
    calcHist(&gray_image, 1, 0,Mat(), b_hist, 1, &histSize, &histRange,uniform, accumulate);
    // menggambar histogram
    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w,CV_8UC3,Scalar(0, 0, 0));
    /// Normalisasi
    normalize(b_hist, b_hist, 0, histImage.rows,NORM_MINMAX, - 1,Mat());
    /// menggambar Histogram
    for (int i = 1; i < histSize; i++){
        line(histImage,Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),Scalar(235, 235, 224), 2, 8, 0);
    }
    /// Display
    imshow("Histogram Grayscale", histImage);
    waitKey();
    return 0;
}
