#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

using namespace cv;
using namespace std;

Mat img;
Mat templ;
Mat result;
string image_window = "Source Image";
string result_window = "Result window";
int match_method;
int max_Trackbar = 5;
int maxpyrlevel = 3;
void MatchingMethod(int, void*);

void MatchingMethod(int, void*)
{
    Mat img_display, maskup, maskdown;
    img.copyTo(img_display);
    int result_cols = img.cols - templ.cols + 1;
    int result_rows = img.rows - templ.rows + 1;
    result.create(result_rows, result_cols, CV_32FC1);
    for (int i = 0; i < maxpyrlevel; i++) {
        if (i == 0) {
            matchTemplate(img, templ, result, match_method);
        } else if (i == 1) {
            pyrUp(templ, maskup);
            matchTemplate(img, maskup, result, match_method);
        } else if (i == 1) {
            pyrUp(templ, maskdown);
            matchTemplate(img, maskdown, result, match_method);
        } else if (i % 2 == 1) {
            pyrUp(templ, maskup);
            matchTemplate(img, maskup, result, match_method);
        } else {
            pyrUp(templ, maskdown);
            matchTemplate(img, maskdown, result, match_method);
        }
        
        normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
        double minVal, maxVal;
        Point minLoc, maxLoc, matchLoc;
        minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
        
        if (match_method == TM_SQDIFF || match_method == TM_SQDIFF_NORMED)
        {
            matchLoc = minLoc;
        } else {
            matchLoc = maxLoc;
        }
        
        if (i == 0) {
            rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);
            
            rectangle(result, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);
            imshow("Detect Template", img_display);
            imshow("Detect Template Result", result);
        } else {
            rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(255), 2, 8, 0);
            rectangle(result, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(255), 2, 8, 0);
        }
    }
    imshow(image_window, img_display);
    imshow(result_window, result);
    return;
}
int main()
{
    img = imread("sunflowers.jpg", 1);
    templ = imread("sunflower.jpg", 1);
    namedWindow(image_window, WINDOW_AUTOSIZE);
    namedWindow(result_window, WINDOW_AUTOSIZE);
    string trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED\n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
    createTrackbar(trackbar_label, image_window, &match_method, max_Trackbar, MatchingMethod);
    MatchingMethod(0, 0);
    waitKey(0);
    return 0;
}
