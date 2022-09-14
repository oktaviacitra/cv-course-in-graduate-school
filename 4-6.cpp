#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
#include <stdio.h>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0);
    String imageCapture = "Image Capture";
    if (cap.isOpened() == false) {
        cout << "Cannot open the video file" << endl;
        cin.get();
        return -1;
    }
    Mat b_hist, g_hist, r_hist;
    int histSize = 256;
    /// Set range
    float range[] = { 0, 256 };
    const float* histRange = { range };
    bool uniform = true;
    bool accumulate = false;
    while (true) {
        Mat frame;
        bool bSuccess = cap.read(frame);
        if (bSuccess == false) {
            cout << "Found the end of the video" << endl;
            break;
        }
        
        /// Memisahkan histogram berdasarkan RGB
        vector<Mat> bgr_planes;
        split(frame, bgr_planes);
        calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
        calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
        calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
        
        // Menggambar histogram
        int hist_w = 512;
        int hist_h = 400;
        int bin_w = cvRound((double)hist_w / histSize);
        Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
        
        /// Normalisasi untuk [ 0, histImage.rows ]
        normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
        normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
        normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

        /// menggambar masing-masing channel
        for (int i = 1; i < histSize; i++) {
            line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))), Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
            line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))), Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0); line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))), Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
        }
        
        if (waitKey(5) == 27) {
            cout << "Esc key is pressed by the user. Stopping the video" << endl;
            break;
        }
        namedWindow(imageCapture, WINDOW_AUTOSIZE);
        namedWindow("Histogram RGB", WINDOW_AUTOSIZE);
        imshow("Image Capture", frame);
        imshow("Histogram RGB", histImage);
    }
    return 0;
}
