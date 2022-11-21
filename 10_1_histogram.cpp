#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat src, dst;
    //load image
    src = imread("sunflowers.jpg", 1);
    if (!src.data)
        return -1;
    //separate the image in 3 places (B G R)
    vector<Mat>bgr_planes;
    split(src, bgr_planes);
    //establish the number of bins
    int histSize = 256;
    //set the range for bgr
    float range[] = { 0, 256 };
    const float* histRange = { range };
    bool uniform = true;
    bool accumulate = false;
    Mat b_hist, g_hist, r_hist;
    //compute the histogram
    calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
    //draw the histogram for bgr
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
    //normalize the result to [0, histImage.rows]
    
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    //draw for each channe;
    for (int i = 0; i < histSize; i++)
    {
        line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))), Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
        line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))), Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0);
        line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))), Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
    }
    //display
    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", src);
    namedWindow("calcHist Demo", WINDOW_AUTOSIZE);
    imshow("calcHist Demo", histImage);
    waitKey(0);
    return 0;
}
