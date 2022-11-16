#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/mat.hpp>

using namespace cv;
using namespace std;

class image {
public:
    Mat im, im1, im2, im3, im4, im5, im6, temp, im11, im12, im13, im14,
    imi, imd, imr;
    float a, b, c, d;
    int getim();
};

int image::getim() {
    im = imread("batik.jpg", 0); //load image in gray scale
    Mat im_res(1024, 1024, CV_8UC1);
    resize(im, im_res, Size(1024, 1024), 0, 0, 1);
    imi = Mat::zeros(im.rows, im.cols, CV_8U);
    im.copyTo(imi);
    int rcnt, ccnt;
    im.convertTo(im, CV_32F, 1.0, 0.0);
    im1 = Mat::zeros(im.rows / 2, im.cols, CV_32F);
    im2 = Mat::zeros(im.rows / 2, im.cols, CV_32F);
    im3 = Mat::zeros(im.rows / 2, im.cols / 2, CV_32F);
    im4 = Mat::zeros(im.rows / 2, im.cols / 2, CV_32F);
    im5 = Mat::zeros(im.rows / 2, im.cols / 2, CV_32F);
    im6 = Mat::zeros(im.rows / 2, im.cols / 2, CV_32F);
    //------------------dekomposisi----------------------//
    for (rcnt = 0; rcnt < im.rows; rcnt += 2) {
        for (ccnt = 0; ccnt < im.cols; ccnt++) {
            a = im.at<float>(rcnt, ccnt);
            b = im.at<float>(rcnt + 1, ccnt);
            c = (a + b)*0.707;
            d = (a - b)*0.707;
            int _rcnt = rcnt / 2;
            im1.at<float>(_rcnt, ccnt) = c;
            im2.at<float>(_rcnt, ccnt) = d;
        }
        
    }
    for (rcnt = 0; rcnt < im.rows / 2; rcnt++) {
        for (ccnt = 0; ccnt < im.cols; ccnt += 2) {
            a = im1.at<float>(rcnt, ccnt);
            b = im1.at<float>(rcnt, ccnt + 1);
            c = (a + b)*0.707;
            d = (a - b)*0.707;
            int _ccnt = ccnt / 2;
            im3.at<float>(rcnt, _ccnt) = c;
            im4.at<float>(rcnt, _ccnt) = d;
        }
    }
    for (rcnt = 0; rcnt < im.rows / 2; rcnt++) {
        for (ccnt = 0; ccnt < im.cols; ccnt += 2) {
            a = im2.at<float>(rcnt, ccnt);
            b = im2.at<float>(rcnt, ccnt + 1);
            c = (a + b)*0.707;
            d = (a - b)*0.707;
            int _ccnt = ccnt / 2;
            im5.at<float>(rcnt, _ccnt) = c;
            im6.at<float>(rcnt, _ccnt) = d;
        }
    }
    imr = Mat::zeros(im.rows, im.cols, CV_32F);
    imd = Mat::zeros(im.rows, im.cols, CV_32F);
    im3.copyTo(imd(Rect(0, 0, im.cols*0.5, im.rows*0.5)));
    im4.copyTo(imd(Rect(0, im.rows*0.5 - 1, im.cols*0.5, im.rows*0.5)));
    im5.copyTo(imd(Rect(im.cols*0.5 - 1, 0, im.cols*0.5, im.rows*0.5)));
    im6.copyTo(imd(Rect(im.cols*0.5 - 1, im.rows*0.5 - 1, im.cols*0.5, im.rows*0.5)));
    //---------------------rekontruksi-----------------------------//
    im11 = Mat::zeros(im.rows / 2, im.cols, CV_32F);
    im12 = Mat::zeros(im.rows / 2, im.cols, CV_32F);
    im13 = Mat::zeros(im.rows / 2, im.cols, CV_32F);
    im14 = Mat::zeros(im.rows / 2, im.cols, CV_32F);
    for (rcnt = 0; rcnt < im.rows / 2; rcnt++) {
        for (ccnt = 0; ccnt < im.cols / 2; ccnt++) {
            int _ccnt = ccnt * 2;
            im11.at<float>(rcnt, _ccnt) = im3.at<float>(rcnt, ccnt);
            
            //upsampling of stage I
            im12.at<float>(rcnt, _ccnt) = im4.at<float>(rcnt, ccnt);
            im13.at<float>(rcnt, _ccnt) = im5.at<float>(rcnt, ccnt);
            im14.at<float>(rcnt, _ccnt) = im6.at<float>(rcnt, ccnt);
        }
    }
    
    for (rcnt = 0; rcnt < im.rows / 2; rcnt++) {
        for (ccnt = 0; ccnt < im.cols; ccnt += 2) {
            a = im11.at<float>(rcnt, ccnt);
            b = im12.at<float>(rcnt, ccnt);
            c = (a + b)*0.707;
            im11.at<float>(rcnt, ccnt) = c;
            d = (a - b)*0.707;
            
            //filtering at stage I
            im11.at<float>(rcnt, ccnt + 1) = d;
            a = im13.at<float>(rcnt, ccnt);
            b = im14.at<float>(rcnt, ccnt);
            c = (a + b)*0.707;
            im13.at<float>(rcnt, ccnt) = c;
            d = (a - b)*0.707;
            im13.at<float>(rcnt, ccnt + 1) = d;
        }
    }
    
    temp = Mat::zeros(im.rows, im.cols, CV_32F);
    for (rcnt = 0; rcnt < im.rows / 2; rcnt++) {
        for (ccnt = 0; ccnt < im.cols; ccnt++) {
            int _rcnt = rcnt * 2;
            imr.at<float>(_rcnt, ccnt) = im11.at<float>(rcnt, ccnt);
            
            //unsampling at stange II
            temp.at<float>(_rcnt, ccnt) = im13.at<float>(rcnt, ccnt);
        }
    }
    
    for (rcnt = 0; rcnt < im.rows; rcnt += 2) {
        for (ccnt = 0; ccnt < im.cols; ccnt++) {
            a = imr.at<float>(rcnt, ccnt);
            b = temp.at<float>(rcnt, ccnt);
            c = (a + b)*0.707;
            imr.at<float>(rcnt, ccnt) = c;
            d = (a - b)*0.707;
            //filtering at stage I
            imr.at<float>(rcnt + 1, ccnt) = d;
        }
    }
    imd.convertTo(imd, CV_8U);
    namedWindow("input image", 1);
    imshow("input image", imi);
    namedWindow("wavelet decomposition", 1);
    imshow("wavelet decomposition", imd);
    imwrite("hasil.jpg", imd);
    imr.convertTo(imr, CV_8U);
    namedWindow("wavelet reconstruction", 1);
    imshow("wavelet reconstruction", imr);
    waitKey(0);
    return 0;
}

int main()
{
    image my;
    my.getim();
    return 0;
}
