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
    Mat src, dst;
    const char* source_window = "Source image";
    const char* equalized_window = "Equalized Image";
    /// Load image
    src = imread("sample.jpg", 1);
    if (!src.data) {
        cout << "Usage: ./Histogram_Demo <path_to_image>" << endl;
        return -1;
    }
    /// Convert to grayscale
    cvtColor(src, src, COLOR_BGR2GRAY);
    /// Apply Histogram Equalization
    equalizeHist(src, dst);
    /// Display results
    namedWindow(source_window, WINDOW_AUTOSIZE);
    namedWindow(equalized_window, WINDOW_AUTOSIZE);
    imshow(source_window, src);
    imshow(equalized_window, dst);
    /// Wait until user exits the program
    waitKey(0);
    return 0;
}
