#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;
//global variabel
Mat img, temp1, result;
string image_window = "Source Image";
string result_window = "Result window";
int match_method;
int max_Trackbar = 5;
//function header
void MatchingMethod(int, void*);
//main function

int main(int argc, char** argv)
{
    //load image and template
    img = imread("sunflowers.jpg", 1);
    temp1 = imread("sunflower.jpg", 1);
    //create windows
    namedWindow(image_window, WINDOW_AUTOSIZE);
    namedWindow(result_window, WINDOW_AUTOSIZE);
    //create track bar
    string trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
    createTrackbar(trackbar_label, image_window, &match_method, max_Trackbar, MatchingMethod);
    MatchingMethod(0, 0);
    waitKey(0);
    return 0;
}
//function MatchingMethod
void MatchingMethod(int, void*) {
    Mat img_display;
    img.copyTo(img_display);
    //create the rasult matriks
    int result_cols = img.cols - temp1.cols + 1;
    int result_rows = img.rows - temp1.rows + 1;
    result.create(result_rows, result_cols, CV_32FC1);
    //do the matching and normalize
    matchTemplate(img, temp1, result, match_method);
    normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
    //localizing the best match with minMaxLoc
    double minVal, maxVal;
    Point minLoc, maxLoc, matchLoc;
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
    //for SQDFF and SQDFF NORMED, the best matches are lower value, for all
    //other methods, the higher the better
    if (match_method == TM_SQDIFF || match_method == TM_SQDIFF_NORMED)
        matchLoc = minLoc;
    else
        matchLoc = maxLoc;
    //show what we got
    rectangle(img_display, matchLoc, Point(matchLoc.x + temp1.cols,
                                           matchLoc.y + temp1.rows), Scalar::all(0), 2, 8, 0);
    rectangle(result, matchLoc, Point(matchLoc.x + temp1.cols,
                                      matchLoc.y + temp1.rows), Scalar::all(0), 2, 8, 0);
    imshow(image_window, img_display);
    imshow(result_window, result);
    return;
}
