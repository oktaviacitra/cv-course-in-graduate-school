#include <math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

Mat mkKernel(int ks, double sig, double th, double lm, double ps) {
    int hks = (ks - 1) / 2;
    double theta = th * CV_PI / 180;
    double psi = ps * CV_PI / 180;
    double del = 2.0 / (ks - 1);
    double lmbd = lm;
    double sigma = sig / ks;
    double x_theta;
    double y_theta;
    Mat kernel(ks, ks, CV_32F);
    for (int y = -hks; y <= hks; y++) {
        for (int x = -hks; x <= hks; x++) {
            x_theta = x * del*cos(theta) + y * del*sin(theta);
            y_theta = -x * del*sin(theta) + y * del*cos(theta);
            kernel.at<float>(hks + y, hks + x) = (float)exp(-0.5*(pow(x_theta, 2) + pow(y_theta, 2)) / pow(sigma, 2))*cos(2 * CV_PI*x_theta / lmbd + psi);
            
        }
    }
    return kernel;
}

int kernel_size = 21;
int pos_sigma = 5;
int pos_lm = 50;
int pos_th = 0;
int pos_psi = 90;
Mat src_f, dest;

void Process(int, void *) {
    double sig = pos_sigma;
    double lm = 0.5 + pos_lm / 100.0;
    double th = pos_th;
    double ps = pos_psi;
    Mat kernel = mkKernel(kernel_size, sig, th, lm, ps);
    filter2D(src_f, dest, CV_32F, kernel);
    imshow("Process Window", dest);
    Mat Lkernel(kernel_size * 20, kernel_size * 20, CV_32F);
    resize(kernel, Lkernel, Lkernel.size());
    Lkernel /= 2.0;
    Lkernel += 0.5;
    imshow("Kernel", Lkernel);
    Mat mag;
    pow(dest, 2.0, mag);
    imshow("Mag", mag);
}

int main()
{
    Mat image = imread("sunflowers.jpg", 1);
    imshow("Src", image);
    Mat src;
    cvtColor(image, src, COLOR_BGR2GRAY);
    src.convertTo(src_f, CV_32F, 1.0 / 255, 0);
    if (!kernel_size % 2)
        kernel_size += 1;
    namedWindow("Process window", 1);
    createTrackbar("Sigma", "Process window", &pos_sigma, kernel_size, Process);
    createTrackbar("Lamda", "Process window", &pos_lm, 100, Process);
    createTrackbar("Theta", "Process window", &pos_th, 180, Process);
    createTrackbar("Psi", "Process window", &pos_psi, 360, Process);
    Process(0, 0);
    waitKey(0);
    return 0;
}
