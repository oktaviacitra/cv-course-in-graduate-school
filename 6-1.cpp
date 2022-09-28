#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src, dst, bw;
    src = imread("sample.jpg", 1);
    cvtColor(src, bw, COLOR_BGR2GRAY);
    threshold(bw, bw, 40, 255, THRESH_BINARY | THRESH_OTSU);
    //creating structuring element
    int dilation_size = 3; //ukuran operator dilasi
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2 * dilation_size + 1, 2 * dilation_size + 1), Point(dilation_size, dilation_size));
    dilate(bw, dst, element);
    imshow("Result Window", dst);
    imshow("Display Window", bw);
    waitKey();
    return 0;
}
