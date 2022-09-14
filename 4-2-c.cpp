#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

void rgb2xyz(Mat image) {
    int r, g, b;
    Mat xyz = image;
    // convert RGB image to XYZ
    
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            b = image.at<Vec3b>(i, j)[0];
            g = image.at<Vec3b>(i, j)[1];
            r = image.at<Vec3b>(i, j)[2];
            xyz.at<Vec3b>(i, j)[2] = r * 0.019334 + g * 0.119193 + b * 0.950227;
            xyz.at<Vec3b>(i, j)[1] = r * 0.212671 + g * 0.715160 + b * 0.072169;
            xyz.at<Vec3b>(i, j)[0] = r * 0.412453 + g * 0.357580 + b * 0.180423;
        }
    }
    imshow("Result XYZ", xyz);
}

void rgb2YCrCb(Mat image) {
    Mat ycrcb = image;
    int r, g, b;
    // convert RGB image to YCrCb
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            b = image.at<Vec3b>(i, j)[0];
            g = image.at<Vec3b>(i, j)[1];
            r = image.at<Vec3b>(i, j)[2];
            ycrcb.at<Vec3b>(i, j)[0] = (b*0.114) + (g*0.587) + (r*0.299);
            ycrcb.at<Vec3b>(i, j)[1] = ((r - ycrcb.at<Vec3b>(i, j)[0]) * 0.713) + 128;
            ycrcb.at<Vec3b>(i, j)[2] = ((b - ycrcb.at<Vec3b>(i, j)[0]) * 0.564) + 128;
        }
    }
    imshow("Result YCrCb", ycrcb);
}

void rgb2HSV(Mat image) {
    Mat hsv = image;
    int r, g, b;
    double h, s, v;
    // convert RGB image to HSV
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            double b = image.at<Vec3b>(i, j)[0]/255.0;
            double g = image.at<Vec3b>(i, j)[1]/255.0;
            double r = image.at<Vec3b>(i, j)[2]/255.0;
            v = max(b, max(g, r));
            if (v == 0) {
                s = 0;
            } else {
                s = (v-min(b, min(g, r)))/v;
            }
            if ((v - min(b, min(g, r))) != 0) {
                if (v==r) {
                    h = 60*(g-b)/(v-min(b, min(g, r)));
                } else if (v==g) {
                    h = 120+((60*(b-r))/(v-min(b, min(g, r))));
                } else if (v == b) {
                    h = 240+((60*(r-g))/(v-min(b, min(g, r))));
                }
            }
            if (h < 0) {
                h = h+360;
            }
            hsv.at<Vec3b>(i, j)[0] = h/2;
            hsv.at<Vec3b>(i, j)[1] = 255*s;
            hsv.at<Vec3b>(i, j)[2] = 255*v;
        }
    }
    imshow("Result HSV", hsv);
}

void rgb2Lab(Mat image) {
    Mat lab = image;
    Mat xyz = image;
    int r, g, b;
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            double b = image.at<Vec3b>(i, j)[0];
            double g = image.at<Vec3b>(i, j)[1];
            double r = image.at<Vec3b>(i, j)[2];
            
            xyz.at<Vec3b>(i, j)[2] = ((r*0.019334)+(g*0.119193)+(b*0.950227))/1.088754;
            xyz.at<Vec3b>(i, j)[1] = ((r*0.212671)+(g*0.715160)+(b*0.072169));
            xyz.at<Vec3b>(i, j)[0] = ((r*0.412453)+(g*0.357580)+(b*0.180423))/0.950456;
            if (xyz.at<Vec3b>(i, j)[1] > 0.008856){
                lab.at<Vec3b>(i, j)[2] = ((116*(pow(xyz.at<Vec3b>(i, j)[1], 0.333333)))-16);
            } else if (xyz.at<Vec3b>(i, j)[1] <= 0.008856) {
                lab.at<Vec3b>(i, j)[2] = 903.3*xyz.at<Vec3b>(i, j)[1];
            }
            lab.at<Vec3b>(i, j)[1] = (500*(float(xyz.at<Vec3b>(i, j)[0])-float(xyz.at<Vec3b>(i, j)[1])))+128;
            lab.at<Vec3b>(i, j)[0] = (200*(float(xyz.at<Vec3b>(i, j)[1])-float(xyz.at<Vec3b>(i, j)[2])))+128;
        }
    }
    imshow("Lab", lab);
}

int main()
{
    Mat image = imread("sample.jpg", IMREAD_COLOR);
    if (!image.data) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }
    rgb2xyz(image);
    rgb2YCrCb(image);
    rgb2HSV(image);
    rgb2Lab(image);
    waitKey(0);
    return 0;
}
