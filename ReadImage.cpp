#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string path = "/Users/oktaviacitra/Downloads/test.jpg";
    cv::Mat img = cv::imread(path, 1);
    cv::namedWindow("Test");
    cv::imshow("Test", img);
    cv::waitKey(0);
    return 0;
}
