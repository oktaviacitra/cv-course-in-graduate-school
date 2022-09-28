#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src, dst_erode, dst_dilate, bw;
    src = imread("sample.jpg", 1);
    cvtColor(src, bw, COLOR_BGR2GRAY);
    threshold(bw, bw, 40, 255, THRESH_BINARY | THRESH_OTSU);
    //creating structuring element
    int opening_size = 3; //ukuran operator opening
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2 * opening_size + 1, 2 * opening_size + 1), Point(opening_size, opening_size));
    //apply opening on the image
    erode(bw, dst_erode, element);
    dilate(dst_erode, dst_dilate, element);
    imshow("Display Window", bw);
    imshow("Result Window", dst_dilate);
    waitKey();
    return 0;
}
