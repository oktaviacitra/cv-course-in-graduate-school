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
    int n = 10;
    //apply opening on the image
    for (int i = 0; i < n; i++) {
        erode(bw, dst_erode, element, Point(-1, -1), i);
        dilate(dst_erode, dst_dilate, element, Point(-1, -1), i);
        imshow("Result Window", dst_dilate);
    }
    imshow("Display Window", bw);
    waitKey();
    return 0;
}
